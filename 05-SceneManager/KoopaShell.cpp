#include "KoopaShell.h"

CKoopaShell::CKoopaShell(float x, float y, int color) : CGameObject(x,y) {
	this->ax = 0;
	this->ay = KOOPA_SHELL_GRAVITY;
	this->state = KOOPA_SHELL_STATE_STOP;
	this->color = color;
	this->vx = 0;
	this->vy = 0;
}

void CKoopaShell::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {
	vx += ax * dt;
	vy += ay * dt;
	CCollision::GetInstance()->Process(this, dt, coObjects);
}

void CKoopaShell::Render() {
	if (this->state == KOOPA_SHELL_STATE_MOVING) {
		CAnimations* animations = CAnimations::GetInstance();
		animations->Get(ID_ANI_KOOPA_SHELL_ROTATE)->Render(x,y);
	}
	else {
		CSprites* s = CSprites::GetInstance();
		s->Get(ID_SPRITE_KOOPA_SHELL)->Draw(x, y);
	}
	RenderBoundingBox();
}

void CKoopaShell::StartMove(float mx) {
	this->state = KOOPA_SHELL_STATE_MOVING;
	if (mx >= this->x) {
		this->vx = -KOOPA_SHELL_SPEED;
	}
	else {
		this->vx = KOOPA_SHELL_SPEED;
	}
}


void CKoopaShell::GetBoundingBox(float& l, float& t, float& r, float& b) {
	l = x - KOOPA_SHELL_BBOX_WIDTH / 2;
	t = y - KOOPA_SHELL_BBOX_HEIGHT / 2;
	r = l+ KOOPA_SHELL_BBOX_WIDTH;
	b= t + KOOPA_SHELL_BBOX_HEIGHT;
}

void CKoopaShell::OnNoCollision(DWORD dt) {
	x += vx * dt;
	y += vy * dt;
}

void CKoopaShell::OnCollisionWith(LPCOLLISIONEVENT e) {
	if (!e->obj->IsBlocking()) return;
	if (dynamic_cast<CKoopaShell*>(e->obj)) return;
	if (dynamic_cast<CGiftBox*>(e->obj)) {
		CGiftBox* box = dynamic_cast<CGiftBox*>(e->obj);
		if (box->GetState() != GIFTBOX_STATE_OPENED)
		{
			box->SetState(GIFTBOX_STATE_OPENED);
			box->StartMove();
			box->GenerateGift();
		}
	}
	if (e->ny != 0)
	{
		vy = 0;
	}
	else if (e->nx != 0)
	{
		vx = -vx;
	}
}