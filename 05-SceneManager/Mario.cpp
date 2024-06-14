#include <algorithm>
#include "debug.h"

#include "Mario.h"
#include "Game.h"

#include "Goomba.h"
#include "Mushroom.h"
#include "Coin.h"
#include "Portal.h"
#include "CColorBox.h"
#include "CGiftBox.h"
#include "Collision.h"
#include "Koopa.h"
#include "KoopaShell.h"
#include "FireBullet.h"
#include "WingedGoomba.h"
#include "Leaf.h"


void CMario::Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects)
{
	vy += ay * dt;
	vx += ax * dt;

	if (abs(vx) > abs(maxVx)) vx = maxVx;

	// reset untouchable timer if untouchable time has passed
	if ( GetTickCount64() - untouchable_start > MARIO_UNTOUCHABLE_TIME) 
	{
		untouchable_start = 0;
		untouchable = 0;
	}

	if (GetTickCount64() - kick_start > MARIO_KICK_TIME) {
		kick_start = 0;
		inKickAni = false;
	}

	if (GetTickCount64() - spin_start > MARIO_SPIN_TIME) {
		spin_start = 0;
		isSpin = false;
	}

	isOnPlatform = false;

	CCollision::GetInstance()->Process(this, dt, coObjects);

	if (this->isHoldingShell) {
		if (vx > 0) {
			this->shell->SetPosition(this->x + MARIO_SHELL_X_OFF_SET, this->y - MARIO_SHELL_Y_OFF_SET );
		}
		else if (vx < 0 ) {
			this->shell->SetPosition(this->x - MARIO_SHELL_X_OFF_SET, this->y - MARIO_SHELL_Y_OFF_SET);
		}
		else {
			float sx, sy;
			this->shell->GetPosition(sx, sy);
			this->shell->SetPosition(sx, this->y - MARIO_SHELL_Y_OFF_SET);
		}
	}
}

void CMario::OnNoCollision(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;

}

void CMario::OnCollisionWith(LPCOLLISIONEVENT e)
{
	if (e->ny != 0 && e->obj->IsBlocking())
	{
		vy = 0;
		if (e->ny < 0) isOnPlatform = true;
	}
	else 
	if (e->nx != 0 && e->obj->IsBlocking())
	{
		vx = 0;
	}


	if (dynamic_cast<CWingedGoomba*>(e->obj))
		OnCollisionWithWingedGoomba(e);
	else if (dynamic_cast<CGoomba*>(e->obj))
		OnCollisionWithGoomba(e);
	else if (dynamic_cast<CCoin*>(e->obj))
		OnCollisionWithCoin(e);
	else if (dynamic_cast<CPortal*>(e->obj))
		OnCollisionWithPortal(e);
	else if (dynamic_cast<CGiftBox*>(e->obj))
		OnCollosionWithGiftBox(e);
	else if (dynamic_cast<CMushroom*>(e->obj))
		OnCollisionWithMushroom(e);
	else if (dynamic_cast<CKoopa*>(e->obj))
		OnCollisionWithKoopa(e);
	else if (dynamic_cast<CKoopaShell*>(e->obj))
		OnCollisionWithKoopaShell(e);
	else if (dynamic_cast<CFireBullet*>(e->obj))
		OnCollisionWithFireBullet(e);
	else if (dynamic_cast<CLeaf*>(e->obj))
		OnCollisionWithLeaf(e);

}

void CMario::OnCollisionWithLeaf(LPCOLLISIONEVENT e)
{
	CLeaf* leaf = dynamic_cast<CLeaf*>(e->obj);
	if (this->level == MARIO_LEVEL_SMALL) {
		this->SetLevel(MARIO_LEVEL_BIG);
	}
	else
		this->SetLevel(MARIO_LEVEL_RACOON_FORM);

	leaf->Delete();
}

void CMario::OnCollisionWithEnemy(LPCOLLISIONEVENT e)
{
	if (level > MARIO_LEVEL_SMALL)
	{
		if (level == MARIO_LEVEL_RACOON_FORM)
		{
			level = MARIO_LEVEL_BIG;
		}
		else
		{
			level = MARIO_LEVEL_SMALL;
		}
		StartUntouchable();
	}
	else
	{
		DebugOut(L">>> Mario DIE >>> \n");
		SetState(MARIO_STATE_DIE);
	}

}



void CMario::OnCollisionWithWingedGoomba(LPCOLLISIONEVENT e)
{
	CWingedGoomba* goomba = dynamic_cast<CWingedGoomba*>(e->obj);

	if (CanKillEnemy(e))
	{
		if (goomba->GetState() != WINGED_GOOMBA_STATE_NO_WINGS_WALKING) {
			goomba->SetState(WINGED_GOOMBA_STATE_NO_WINGS_WALKING);
		}
		else {
			goomba->SetState(WINGED_GOOMBA_STATE_DIE);
		}
	}
	else 
	{
		if (untouchable == 0)
		{
			if (goomba->GetState() != WINGED_GOOMBA_STATE_DIE)
			{
				OnCollisionWithEnemy(e);
			}
		}
	}
}



void CMario::OnCollisionWithKoopa(LPCOLLISIONEVENT e) {
	CKoopa* koopa = dynamic_cast<CKoopa*>(e->obj);
	if (CanKillEnemy(e))
	{
		koopa->EnterShell();
		if (e->ny < 0)
			vy = -MARIO_JUMP_DEFLECT_SPEED;
	}
	else // hit by Koopa
	{
		if (untouchable == 0)
		{
			OnCollisionWithEnemy(e);
		}
	}
}

void CMario::HoldShell(CKoopaShell* shell) {
	this->isHoldingShell = true;
	this->shell = shell;
}
void CMario::ReleaseShell() {
	this->isHoldingShell = false;
	this->shell->StartMove(this->x);
	this->shell = NULL;
	this->StartKickAni();
}


void CMario::OnCollisionWithKoopaShell(LPCOLLISIONEVENT e) {
	CKoopaShell* shell = dynamic_cast<CKoopaShell*>(e->obj);
	if (shell->GetState() == KOOPA_SHELL_STATE_STOP) {
		if (abs(ax) == MARIO_ACCEL_RUN_X && e->nx != 0 )  {
			this->HoldShell(shell);
		} else {
			this->StartKickAni();
			shell->StartMove(x);
		}
	}
	else {
		if (e->ny < 0)
		{
			shell->StopMove();
		}
		else if (untouchable == 0)
		{
			OnCollisionWithEnemy(e);
		}
	}
}

void CMario::OnCollisionWithFireBullet(LPCOLLISIONEVENT e)
{
	CFireBullet* bullet = dynamic_cast<CFireBullet*>(e->obj);
	if (untouchable == 0)
	{
		OnCollisionWithEnemy(e);
	}
}



void CMario::OnCollisionWithMushroom(LPCOLLISIONEVENT e) {
	CMushroom* mushroom = dynamic_cast<CMushroom*>(e->obj);
	this->SetLevel(MARIO_LEVEL_BIG);
	mushroom->Delete();
}
void CMario::OnCollosionWithGiftBox(LPCOLLISIONEVENT e) {
	CGiftBox* box = dynamic_cast<CGiftBox*>(e->obj);
	float mx, my;
	box->GetPosition(mx, my);
	if (e->ny > 0)
	{ 
		if (box->GetState() != GIFTBOX_STATE_OPENED)
		{
			box->SetState(GIFTBOX_STATE_OPENED);
			box->StartMove();
			box->GenerateGift();
		}
	}
}



void CMario::OnCollisionWithGoomba(LPCOLLISIONEVENT e)
{
	CGoomba* goomba = dynamic_cast<CGoomba*>(e->obj);

	// jump on top >> kill Goomba and deflect a bit 
	if (CanKillEnemy(e))
	{
		if (goomba->GetState() != GOOMBA_STATE_DIE)
		{
			goomba->SetState(GOOMBA_STATE_DIE);
			if (e->ny < 0)
			vy = -MARIO_JUMP_DEFLECT_SPEED;
		}
	}
	else // hit by Goomba
	{
		if (untouchable == 0)
		{
			if (goomba->GetState() != GOOMBA_STATE_DIE)
			{
				OnCollisionWithEnemy(e);
			}
		}
	}
}

void CMario::OnCollisionWithCoin(LPCOLLISIONEVENT e)
{
	e->obj->Delete();
	coin++;
}

void CMario::OnCollisionWithPortal(LPCOLLISIONEVENT e)
{
	CPortal* p = (CPortal*)e->obj;
	CGame::GetInstance()->InitiateSwitchScene(p->GetSceneId());
}

//
// Get animation ID for small Mario
//
int CMario::GetAniIdSmall()
{
	int aniId = -1;
	if (inKickAni) {
		if (nx >= 0) {
			aniId = ID_ANI_MARIO_SMALL_RIGHT_KICK;
		}
		else {
			aniId = ID_ANI_MARIO_SMALL_LEFT_KICK;
		}
	}
	else if (!isOnPlatform)
	{
		if (isHoldingShell) {
			if (nx >= 0)
				aniId = ID_ANI_MARIO_SMALL_HOLDING_SHELL_JUMP_RIGHT;
			else
				aniId = ID_ANI_MARIO_SMALL_HOLDING_SHELL_JUMP_LEFT;
		}
		else if (abs(ax) == MARIO_ACCEL_RUN_X)
		{
				if (nx >= 0)
					aniId = ID_ANI_MARIO_SMALL_JUMP_RUN_RIGHT;
				else
					aniId = ID_ANI_MARIO_SMALL_JUMP_RUN_LEFT;
		}
		else
		{
			if (nx >= 0)
				aniId = ID_ANI_MARIO_SMALL_JUMP_WALK_RIGHT;
			else
				aniId = ID_ANI_MARIO_SMALL_JUMP_WALK_LEFT;
		}
	}
	else if (isHoldingShell) {
		if (vx > 0) {
			aniId = ID_ANI_MARIO_SMALL_HOLDING_SHELL_RUN_RIGHT;
		}
		else if (vx < 0) {
			aniId = ID_ANI_MARIO_SMALL_HOLDING_SHELL_RUN_LEFT;
		}
		else {
			if (nx > 0) aniId = ID_ANI_MARIO_SMALL_HOLDING_SHELL_IDLE_RIGHT;
			else aniId = ID_ANI_MARIO_SMALL_HOLDING_SHELL_IDLE_LEFT;
		}
	}
	else
		if (isSitting)
		{
			if (nx > 0)
				aniId = ID_ANI_MARIO_SIT_RIGHT;
			else
				aniId = ID_ANI_MARIO_SIT_LEFT;
		}
		else
			if (vx == 0)
			{
				if (nx > 0) aniId = ID_ANI_MARIO_SMALL_IDLE_RIGHT;
				else aniId = ID_ANI_MARIO_SMALL_IDLE_LEFT;
			}
			else if (vx > 0)
			{
				if (ax < 0)
					aniId = ID_ANI_MARIO_SMALL_BRACE_RIGHT;
				else if (ax == MARIO_ACCEL_RUN_X) {
					aniId = ID_ANI_MARIO_SMALL_RUNNING_RIGHT;
				}
				else if (ax == MARIO_ACCEL_WALK_X)
					aniId = ID_ANI_MARIO_SMALL_WALKING_RIGHT;
			}
			else // vx < 0
			{
				if (ax > 0)
					aniId = ID_ANI_MARIO_SMALL_BRACE_LEFT;
				else if (ax == -MARIO_ACCEL_RUN_X) {
					aniId = ID_ANI_MARIO_SMALL_RUNNING_LEFT;
				}
				else if (ax == -MARIO_ACCEL_WALK_X)
					aniId = ID_ANI_MARIO_SMALL_WALKING_LEFT;
			}

	if (aniId == -1) aniId = ID_ANI_MARIO_SMALL_IDLE_RIGHT;

	return aniId;
}


//
// Get animdation ID for big Mario
//
int CMario::GetAniIdBig()
{
	int aniId = -1;

	if (inKickAni) {
		if (nx >= 0) {
			aniId = ID_ANI_MARIO_RIGHT_KICK;
		}
		else {
			aniId = ID_ANI_MARIO_LEFT_KICK;
		}
	}
	else if (!isOnPlatform)
	{

		if (isHoldingShell) {
			if (nx >= 0)
				aniId = ID_ANI_MARIO_HOLDING_SHELL_JUMP_RIGHT;
			else
				aniId = ID_ANI_MARIO_HOLDING_SHELL_JUMP_LEFT;
		}
		else if (abs(ax) == MARIO_ACCEL_RUN_X)
		{
			if (nx >= 0)
				aniId = ID_ANI_MARIO_JUMP_RUN_RIGHT;
			else
				aniId = ID_ANI_MARIO_JUMP_RUN_LEFT;
		}
		else
		{
			if (nx >= 0)
				aniId = ID_ANI_MARIO_JUMP_WALK_RIGHT;
			else
				aniId = ID_ANI_MARIO_JUMP_WALK_LEFT;
		}
	}
	else if (isHoldingShell) {
		if (vx > 0) {
			aniId = ID_ANI_MARIO_HOLDING_SHELL_RUN_RIGHT;
		}
		else if (vx < 0) {
			aniId = ID_ANI_MARIO_HOLDING_SHELL_RUN_LEFT;
		}
		else {
			if (nx > 0) aniId = ID_ANI_MARIO_HOLDING_SHELL_IDLE_RIGHT;
			else aniId = ID_ANI_MARIO_HOLDING_SHELL_IDLE_LEFT;
		}
	}
	else
		if (isSitting)
		{
			if (nx > 0)
				aniId = ID_ANI_MARIO_SIT_RIGHT;
			else
				aniId = ID_ANI_MARIO_SIT_LEFT;
		}
		else
			if (vx == 0)
			{
				if (nx > 0) aniId = ID_ANI_MARIO_IDLE_RIGHT;
				else aniId = ID_ANI_MARIO_IDLE_LEFT;
			}
			else if (vx > 0)
			{
				if (ax < 0)
					aniId = ID_ANI_MARIO_BRACE_RIGHT;
				else if (ax == MARIO_ACCEL_RUN_X) {
					aniId = ID_ANI_MARIO_RUNNING_RIGHT;
				}
				else if (ax == MARIO_ACCEL_WALK_X)
					aniId = ID_ANI_MARIO_WALKING_RIGHT;
			}
			else // vx < 0
			{
				if (ax > 0)
					aniId = ID_ANI_MARIO_BRACE_LEFT;
				else if (ax == -MARIO_ACCEL_RUN_X) {
					if (!isHoldingShell)
						aniId = ID_ANI_MARIO_RUNNING_LEFT;
				}
				else if (ax == -MARIO_ACCEL_WALK_X)
					aniId = ID_ANI_MARIO_WALKING_LEFT;
			}

	if (aniId == -1) aniId = ID_ANI_MARIO_IDLE_RIGHT;

	return aniId;
}

int CMario::GetAniIdRacoon()
{
	int aniId = -1;

	if (inKickAni) {
		if (nx >= 0) {
			aniId = ID_ANI_MARIO_RACOON_RIGHT_KICK;
		}
		else {
			aniId = ID_ANI_MARIO_RACOON_LEFT_KICK;
		}
	}
	else if (isSpin) {
		if (nx > 0) aniId = ID_ANI_MARIO_RACOON_SPIN_RIGHT;
		else aniId = ID_ANI_MARIO_RACOON_SPIN_LEFT;
	}
	else if (!isOnPlatform)
	{

		if (isHoldingShell) {
			if (nx >= 0)
				aniId = ID_ANI_MARIO_RACOON_HOLDING_SHELL_JUMP_RIGHT;
			else
				aniId = ID_ANI_MARIO_RACOON_HOLDING_SHELL_JUMP_LEFT;
		}
		else if (abs(ax) == MARIO_ACCEL_RUN_X)
		{
			if (nx >= 0)
				aniId = ID_ANI_MARIO_RACOON_JUMP_RUN_RIGHT;
			else
				aniId = ID_ANI_MARIO_RACOON_JUMP_RUN_LEFT;
		}
		else
		{
			if (nx >= 0)
				aniId = ID_ANI_MARIO_RACOON_JUMP_WALK_RIGHT;
			else
				aniId = ID_ANI_MARIO_RACOON_JUMP_WALK_LEFT;
		}
	}
	else if (isHoldingShell) {
		if (vx > 0) {
			aniId = ID_ANI_MARIO_RACOON_HOLDING_SHELL_RUN_RIGHT;
		}
		else if (vx < 0) {
			aniId = ID_ANI_MARIO_RACOON_HOLDING_SHELL_RUN_LEFT;
		}
		else {
			if (nx > 0) aniId = ID_ANI_MARIO_RACOON_HOLDING_SHELL_IDLE_RIGHT;
			else aniId = ID_ANI_MARIO_RACOON_HOLDING_SHELL_IDLE_LEFT;
		}
	}

	else
		if (isSitting)
		{
			if (nx > 0)
				aniId = ID_ANI_MARIO_RACOON_SIT_RIGHT;
			else
				aniId = ID_ANI_MARIO_RACOON_SIT_LEFT;
		}
		else
			if (vx == 0)
			{
				if (nx > 0) aniId = ID_ANI_MARIO_RACOON_IDLE_RIGHT;
				else aniId = ID_ANI_MARIO_RACOON_IDLE_LEFT;
			}
			else if (vx > 0)
			{
				if (ax < 0)
					aniId = ID_ANI_MARIO_RACOON_BRACE_RIGHT;
				else if (ax == MARIO_ACCEL_RUN_X) {
					aniId = ID_ANI_MARIO_RACOON_RUNNING_RIGHT;
				}
				else if (ax == MARIO_ACCEL_WALK_X)
					aniId = ID_ANI_MARIO_RACOON_WALKING_RIGHT;
			}
			else // vx < 0
			{
				if (ax > 0)
					aniId = ID_ANI_MARIO_RACOON_BRACE_LEFT;
				else if (ax == -MARIO_ACCEL_RUN_X) {
					if (!isHoldingShell)
						aniId = ID_ANI_MARIO_RACOON_RUNNING_LEFT;
				}
				else if (ax == -MARIO_ACCEL_WALK_X)
					aniId = ID_ANI_MARIO_RACOON_WALKING_LEFT;
			}

	if (aniId == -1) aniId = ID_ANI_MARIO_RACOON_IDLE_RIGHT;

	return aniId;


	return 0;
}



void CMario::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	int aniId = -1;

	if (state == MARIO_STATE_DIE)
		aniId = ID_ANI_MARIO_DIE;
	else if (level == MARIO_LEVEL_BIG)
		aniId = GetAniIdBig();
	else if (level == MARIO_LEVEL_SMALL)
		aniId = GetAniIdSmall();
	else if (level == MARIO_LEVEL_RACOON_FORM)
		aniId = GetAniIdRacoon();

	animations->Get(aniId)->Render(x, y);

	RenderBoundingBox();
	
	DebugOutTitle(L"Coins: %d", coin);
}

void CMario::SetState(int state)
{
	 //DIE is the end state, cannot be changed! 
	if (this->state == MARIO_STATE_DIE) return; 

	switch (state)
	{
	case MARIO_STATE_RUNNING_RIGHT:
		if (isSitting) break;
		maxVx = MARIO_RUNNING_SPEED;
		ax = MARIO_ACCEL_RUN_X;
		nx = 1;
		break;
	case MARIO_STATE_RUNNING_LEFT:
		if (isSitting) break;
		maxVx = -MARIO_RUNNING_SPEED;
		ax = -MARIO_ACCEL_RUN_X;
		nx = -1;
		break;
	case MARIO_STATE_WALKING_RIGHT:
		if (isSitting) break;
		maxVx = MARIO_WALKING_SPEED;
		ax = MARIO_ACCEL_WALK_X;
		nx = 1;
		break;
	case MARIO_STATE_WALKING_LEFT:
		if (isSitting) break;
		maxVx = -MARIO_WALKING_SPEED;
		ax = -MARIO_ACCEL_WALK_X;
		nx = -1;
		break;
	case MARIO_STATE_JUMP:
		if (isSitting) break;
		if (isOnPlatform)
		{
			if (abs(this->vx) == MARIO_RUNNING_SPEED)
				vy = -MARIO_JUMP_RUN_SPEED_Y;
			else
				vy = -MARIO_JUMP_SPEED_Y;
		}
		break;

	case MARIO_STATE_RELEASE_JUMP:
		if (vy < 0) vy += MARIO_JUMP_SPEED_Y / 2;
		break;

	case MARIO_STATE_SIT:
		if (isOnPlatform && level != MARIO_LEVEL_SMALL)
		{
			state = MARIO_STATE_IDLE;
			isSitting = true;
			vx = 0; vy = 0.0f;
			y +=MARIO_SIT_HEIGHT_ADJUST;
		}
		break;

	case MARIO_STATE_SIT_RELEASE:
		if (isSitting)
		{
			isSitting = false;
			state = MARIO_STATE_IDLE;
			y -= MARIO_SIT_HEIGHT_ADJUST;
		}
		break;

	case MARIO_STATE_IDLE:
		ax = 0.0f;
		vx = 0.0f;
		break;

	case MARIO_STATE_DIE:
		vy = -MARIO_JUMP_DEFLECT_SPEED;
		vx = 0;
		ax = 0;
		break;
	}

	CGameObject::SetState(state);
}

void CMario::GetBoundingBox(float &left, float &top, float &right, float &bottom)
{
	if (level==MARIO_LEVEL_BIG || level == MARIO_LEVEL_RACOON_FORM)
	{
		if (isSitting)
		{
			left = x - MARIO_BIG_SITTING_BBOX_WIDTH / 2;
			top = y - MARIO_BIG_SITTING_BBOX_HEIGHT / 2;
			right = left + MARIO_BIG_SITTING_BBOX_WIDTH;
			bottom = top + MARIO_BIG_SITTING_BBOX_HEIGHT;
		}
		else if (isSpin) {
			left = x - MARIO_BIG_BBOX_WIDTH / 2 -5 ;
			top = y - MARIO_BIG_BBOX_HEIGHT / 2;
			right = left + MARIO_BIG_BBOX_WIDTH + 5;
			bottom = top + MARIO_BIG_BBOX_HEIGHT;
		}
		else 
		{
			left = x - MARIO_BIG_BBOX_WIDTH/2;
			top = y - MARIO_BIG_BBOX_HEIGHT/2;
			right = left + MARIO_BIG_BBOX_WIDTH;
			bottom = top + MARIO_BIG_BBOX_HEIGHT;
		}
	}
	else
	{
		left = x - MARIO_SMALL_BBOX_WIDTH/2;
		top = y - MARIO_SMALL_BBOX_HEIGHT/2;
		right = left + MARIO_SMALL_BBOX_WIDTH;
		bottom = top + MARIO_SMALL_BBOX_HEIGHT;
	}
}

void CMario::SetLevel(int l)
{
	// Adjust position to avoid falling off platform
	if (this->level == MARIO_LEVEL_SMALL)
	{
		y -= (MARIO_BIG_BBOX_HEIGHT - MARIO_SMALL_BBOX_HEIGHT) / 2;
	}
	else if (this->level == MARIO_LEVEL_BIG) {
		y -= (MARIO_BIG_BBOX_HEIGHT - MARIO_SMALL_BBOX_HEIGHT) / 2;
	}


	level = l;
}

