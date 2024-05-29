#include "Koopa.h"

CKoopa::CKoopa(float x, float y, int color, float patrol_radius) : CGameObject(x, y) {
	this->ay = KOOPA_GRAVITY;
	this->vx = KOOPA_WALKING_SPEED;
	this->ax = 0;
	this->color = color;
	this->patrol_radius = patrol_radius;
	if (this->patrol_radius > 0) {
		this->has_patrol_radius = true;
	}
	else {
		this->has_patrol_radius = false;
	}
	this->state = KOOPA_STATE_WALKING_LEFT;
}

void CKoopa::Render() {
	CAnimations* animations = CAnimations::GetInstance();
	animations->Get(this->GetAniId() + this->color)->Render(x, y);
	RenderBoundingBox();
}

void CKoopa::Die() {
	this->isDeleted = true;
	if (dynamic_cast<CPlayScene*>(CGame::GetInstance()->GetCurrentScene())) {
		CPlayScene* scene = (CPlayScene*)(CGame::GetInstance()->GetCurrentScene());
		CKoopaShell* shell = new CKoopaShell(x, y + 2, color);
		scene->AddNewObjectToTail(shell);
	}
}
void CKoopa::GetBoundingBox(float& left, float& top, float& right, float& bottom) {
	left = x - KOOPA_BBOX_WIDTH / 2;
	top = y - KOOPA_BBOX_HEIGHT / 2;
	right = left + KOOPA_BBOX_WIDTH;
	bottom = top + KOOPA_BBOX_HEIGHT;
}

void CKoopa::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {
	vx += ax * dt;
	vy += ay * dt;
	if (has_patrol_radius) {
		float d = abs(initX - x);
		if (d >= patrol_radius) {
			this->vx = -vx;
		}
	}
	CCollision::GetInstance()->Process(this, dt, coObjects);
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