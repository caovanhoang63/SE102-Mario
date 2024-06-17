#include "KoopaShell.h"
#include "CGiftBox.h"


void CKoopaShell::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	vx += ax * dt;
	vy += ay * dt;
	if (this->state == KOOPA_SHELL_STATE_STOP && GetTickCount64() - this->stop_start > KOOPA_SHELL_SHAKE_STOP_TIME) {
		this->state = KOOPA_SHELL_STATE_SHAKE;
	}
	CCollision::GetInstance()->Process(this, dt, coObjects);
}

void CKoopaShell::Render() {
	if (this->state == KOOPA_SHELL_STATE_MOVING) {
		CAnimations* animations = CAnimations::GetInstance();
		animations->Get(ID_ANI_KOOPA_SHELL_ROTATE)->Render(x,y);
	}
	else if (this->state == KOOPA_SHELL_STATE_SHAKE) {
		CAnimations* animations = CAnimations::GetInstance();
		animations->Get(ID_ANI_KOOPA_SHELL_SHAKE)->Render(x, y);
	}
	else {
		CSprites* s = CSprites::GetInstance();
		s->Get(ID_SPRITE_KOOPA_SHELL)->Draw(x, y);
	}
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
	if (dynamic_cast<CEnemy*>(e->obj) && this->state == KOOPA_SHELL_STATE_MOVING) {
		CEnemy* enemy = dynamic_cast<CEnemy*>(e->obj);
		float ex, ey;
		enemy->GetPosition(ex, ey);
		int isHitted = 0;
		if (this->x > ex)
			isHitted = 1;
		else
			isHitted = -1;
		enemy->Hitted(isHitted);
		return;
	}

	if (!e->obj->IsBlocking()) return;

	if (dynamic_cast<CKoopaShell*>(e->obj)) return;

	if (dynamic_cast<CGiftBox*>(e->obj)) {
		CGiftBox* box = dynamic_cast<CGiftBox*>(e->obj);
		if (box->GetState() != GIFTBOX_STATE_OPENED && this->state == KOOPA_SHELL_STATE_MOVING)
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