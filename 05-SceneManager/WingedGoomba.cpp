#include "WingedGoomba.h"
#include "PlayScene.h"

CWingedGoomba::CWingedGoomba(float x, float y) : CGoomba(x,y)
{
	die_start = -1;
	walking_start = -1;
	jumpCount = 0;
	observe_start = GetTickCount64();
	vx = -GOOMBA_WALKING_SPEED;
	SetState(WINGED_GOOMBA_STATE_WALKING);
}

void CWingedGoomba::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	if (state == WINGED_GOOMBA_STATE_DIE)
	{
		left = x - WINGED_GOOMBA_BBOX_WIDTH / 2;
		top = y - WINGED_GOOMBA_BBOX_HEIGHT_DIE / 2;
		right = left + WINGED_GOOMBA_BBOX_WIDTH;
		bottom = top + WINGED_GOOMBA_BBOX_HEIGHT_DIE;
	}
	else if (state == WINGED_GOOMBA_STATE_NO_WINGS_WALKING) {
		left = x - WINGED_GOOMBA_BBOX_WIDTH / 2;
		top = y - WINGED_GOOMBA_NO_WINGS_BBOX_HEIGHT / 2;
		right = left + WINGED_GOOMBA_BBOX_WIDTH;
		bottom = top + WINGED_GOOMBA_NO_WINGS_BBOX_HEIGHT;
	}
	else
	{
		left = x - WINGED_GOOMBA_BBOX_WIDTH / 2;
		top = y - WINGED_GOOMBA_BBOX_HEIGHT / 2;
		right = left + WINGED_GOOMBA_BBOX_WIDTH;
		bottom = top + WINGED_GOOMBA_BBOX_HEIGHT;
	}

}

void CWingedGoomba::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	vy += ay * dt;
	vx += ax * dt;

	Observe();

	if ((state == WINGED_GOOMBA_STATE_DIE) && (GetTickCount64() - die_start > WINGED_GOOMBA_DIE_TIMEOUT))
	{
		isDeleted = true;
		return;
	}

	else if ((state == WINGED_GOOMBA_STATE_WALKING && (GetTickCount64() - walking_start > WINGED_GOOMBA_WALKING_TIME))) 	{
		SetState(WINGED_GOOMBA_STATE_JUMP);
	}
	else if (state == WINGED_GOOMBA_STATE_JUMP){
		if (jumpCount != WINGEG_GOOMBA_NUM_OF_JUMP) {
			if (isOnPlatform)
			{
				vy = -WINGED_GOOMBA_SPEED_JUMP_Y;
				jumpCount++;
			}
		} else {
			SetState(WINGED_GOOMBA_STATE_HIGH_JUMP);
		}
	}

	isOnPlatform = false;
	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);

	if (state == WINGED_GOOMBA_STATE_HIGH_JUMP && isOnPlatform) {
		SetState(WINGED_GOOMBA_STATE_WALKING);
	}

}

void CWingedGoomba::SetState(int state)
{
	CGameObject::SetState(state);
	switch (state)
	{
	case WINGED_GOOMBA_STATE_DIE:
		die_start = GetTickCount64();
		if (isPressed) {
			y += (GOOMBA_BBOX_HEIGHT - GOOMBA_BBOX_HEIGHT_DIE) / 2;
			vx = 0;
			vy = 0;
			ay = 0;
		}
		else {
			vx = isHitted > 0 ? -GOOMBA_WALKING_SPEED : GOOMBA_WALKING_SPEED;
		}
		break;
	case WINGED_GOOMBA_STATE_WALKING:

		walking_start = GetTickCount64();
		break;
	case WINGED_GOOMBA_STATE_JUMP:
		jumpCount = 0;
		break;
	case WINGED_GOOMBA_STATE_HIGH_JUMP:
		vy = -WINGED_GOOMBA_SPEED_HIGH_JUMP_Y;
		break;
	}
}

void CWingedGoomba::Hitted(int nx)
{
	CEnemy::Hitted(nx);
	if (this->GetState() != WINGED_GOOMBA_STATE_DIE) {
		this->SetState(WINGED_GOOMBA_STATE_DIE);
	}
}

void CWingedGoomba::Pressed()
{
	CEnemy::Pressed();
	if (this->GetState() == WINGED_GOOMBA_STATE_NO_WINGS_WALKING) {
		this->SetState(WINGED_GOOMBA_STATE_DIE);
	}
	else {
		this->SetState(WINGED_GOOMBA_STATE_NO_WINGS_WALKING);
	}
}


bool CWingedGoomba::IsInStateDie()
{
	return this->state == WINGED_GOOMBA_STATE_DIE;
}
void CWingedGoomba::Render()
{
	int aniId = -1;
	switch (state)
	{
	case WINGED_GOOMBA_STATE_WALKING:
		aniId = ID_ANI_WINGED_GOOMBA_WALKING;
		break;
	case WINGED_GOOMBA_STATE_JUMP:
		aniId = ID_ANI_WINGED_GOOMBA_JUMP;
		break;
	case WINGED_GOOMBA_STATE_HIGH_JUMP:
		aniId = ID_ANI_WINGED_GOOMBA_HIGH_JUMP;
		break;
	case WINGED_GOOMBA_STATE_DIE:
		if (isPressed)
			aniId = ID_ANI_WINGED_DIE;
		else
			aniId = ID_ANI_WINGED_GOOMBA_NO_WINGS_HITTED;
		break;
	default:
		aniId = ID_ANI_WINGED_GOOMBA_NO_WINGS_WALKING;
		break;
	}
	CAnimations* ani = CAnimations::GetInstance();
	ani->Get(aniId)->Render(x, y);
	RenderBoundingBox();
}

void CWingedGoomba::OnCollisionWith(LPCOLLISIONEVENT e)
{
	if (!e->obj->IsBlocking()) return;
	if (dynamic_cast<CGoomba*>(e->obj)) return;

	if (e->ny != 0 && e->obj->IsBlocking())
	{
		vy = 0;
		if (e->ny < 0) isOnPlatform = true;
	}
	else if (e->nx != 0)
	{
		vx = -vx;
	}
}

void CWingedGoomba::Observe()
{
	if (state == WINGED_GOOMBA_STATE_NO_WINGS_WALKING) return;
	if (GetTickCount64() - observe_start > WINGED_GOOMBA_OBSERVE_TIME) {
		observe_start = GetTickCount64();

		if (state == WINGED_GOOMBA_STATE_HIGH_JUMP) return;
		
		if (dynamic_cast<CPlayScene*>(CGame::GetInstance()->GetCurrentScene())) {
			CPlayScene* scene = dynamic_cast<CPlayScene*>(CGame::GetInstance()->GetCurrentScene());
			float marioX, marioY;
			scene->GetPlayer()->GetPosition(marioX, marioY);
			if (marioX > x) {
				vx = GOOMBA_WALKING_SPEED;
			}
			else {
				vx = -GOOMBA_WALKING_SPEED;
			}
		}
	}
}


