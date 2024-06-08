#include "Koopa.h"
#include "PlayScene.h"

CKoopa::CKoopa(float x, float y, int color) : CEnemy(x, y) {
	this->ay = KOOPA_GRAVITY;
	this->vx = KOOPA_WALKING_SPEED;
	this->ax = 0;
	this->shell = new CKoopaShell(x,y,color);
	this->color = color;
	this->is_in_shell = false;
	this->in_shell_start = -1;
	this->width = KOOPA_BBOX_WIDTH;
	this->height = KOOPA_BBOX_HEIGHT;
	this->block = NULL;
	if (color == KOOPA_COLOR_RED) {
		this->block = new CInvisibleBlock(x, y);
		if (dynamic_cast<CPlayScene*>(CGame::GetInstance()->GetCurrentScene())) {
			CPlayScene* scene = (CPlayScene*)CGame::GetInstance()->GetCurrentScene();
			scene->AddNewObjectToTail(this->block);
		}
	}
	this->state = KOOPA_STATE_WALKING_LEFT;
}


void CKoopa::Render() {
	if (this->is_in_shell) return;
	CAnimations* animations = CAnimations::GetInstance();
	animations->Get(this->GetAniId() + this->color)->Render(x, y);
}

void CKoopa::EnterShell() {
	this->is_in_shell = true;
	this->in_shell_start = GetTickCount64();
	if (dynamic_cast<CPlayScene*>(CGame::GetInstance()->GetCurrentScene())) {
		CPlayScene* scene = (CPlayScene*)(CGame::GetInstance()->GetCurrentScene());
		this->shell = new CKoopaShell(x, y, color);
		this->shell->SetPosition(x, y + 2);
		scene->AddNewObjectToTail(this->shell);
	}
}
void CKoopa::ExitShell()
{
	this->isDeleted = false;
	float sx, sy;
	this->shell->GetPosition(sx, sy);
	this->shell->Delete();
	this->SetPosition(sx, sy - 8);
}
void CKoopa::GetBoundingBox(float& left, float& top, float& right, float& bottom) {
	if (this->is_in_shell) return;
	left = x - this->width / 2;
	top = y - this->height / 2;
	right = left + this->width;
	bottom = top + this->height;
}

void CKoopa::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {
	if (!this->is_in_shell) {
		CEnemy::Update(dt, coObjects);
		vx += ax * dt;
		vy += ay * dt;

		if (this->color == ID_KOOPA_SHELL_COLOR_RED) {
			if (!this->block->isOnPlatform()) { vx = -vx; }
			if (this->vx > 0) {
				this->block->SetToRight(x, y);
			}
			else {
				this->block->SetToLeft(x, y);
			}
		}
		CCollision::GetInstance()->Process(this, dt, coObjects);
	}
	else if (this->shell->GetState() == KOOPA_SHELL_STATE_STOP && GetTickCount64() - this->in_shell_start > KOOPA_IN_SHELL_TIME)
	{
		this->in_shell_start = 0;
		this->is_in_shell = false;
		this->ExitShell();
	}
	else if (this->shell->GetState() == KOOPA_SHELL_STATE_MOVING) {
		this->in_shell_start = GetTickCount64();
	}

}

void CKoopa::SetState(int state) {
	CGameObject::SetState(state);
}

int CKoopa::GetAniId() {
	if (vx > 0) {
		return ID_ANI_KOOPA_WALKING_RIGHT;
	}
	return ID_ANI_KOOPA_WALKING_LEFT;
}

void CKoopa::OnNoCollision(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;
};

void CKoopa::OnCollisionWith(LPCOLLISIONEVENT e)
{
	if (!e->obj->IsBlocking()) return;
	if (dynamic_cast<CKoopa*>(e->obj)) return;

	if (e->ny != 0)
	{
		vy = 0;
	}
	else if (e->nx != 0)
	{
		vx = -vx;
	}
}
