#include "KoopaShell.h"
#include "CGiftBox.h"


CKoopaShell::CKoopaShell(float x, float y, int color, int direction) : CGameObject(x, y) {
	this->ax = 0;
	this->ay = KOOPA_SHELL_GRAVITY;
	this->state = KOOPA_SHELL_STATE_STOP;
	this->direction = direction;
	this->stop_start = GetTickCount64();
	this->color = color;
	this->vx = 0;
	this->vy = 0;
	this->isHittedDeflect = false;
	this->isOnPlatform = false;
}

void CKoopaShell::Hitted(int nx)
{
	this->vy = -KOOPA_SHELL_DEFLECT_SPEED_Y;
	vx = nx > 0 ? -KOOPA_SHELL_DEFLECT_SPEED_X : KOOPA_SHELL_DEFLECT_SPEED_X;
	ax = nx > 0 ? KOOPA_SHELL_DEFLECT_ACCEL_X : -KOOPA_SHELL_DEFLECT_ACCEL_X;
	this->isHittedDeflect = true;
}



void CKoopaShell::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	isOnPlatform = false;
	vx += ax * dt;
	DebugOut(L"vx: %f\n", vx);
	vy += ay * dt;
	if (this->isHittedDeflect && vx * ax >= 0) {
		this->vx = 0;
		this->ax = 0;
		this->isHittedDeflect = false;
	}

	if (this->state == KOOPA_SHELL_STATE_STOP && GetTickCount64() - this->stop_start > KOOPA_SHELL_SHAKE_STOP_TIME) {
		this->state = KOOPA_SHELL_STATE_SHAKE;
	}

	CCollision::GetInstance()->Process(this, dt, coObjects);

}


void CKoopaShell::Render() {
	if (this->state == KOOPA_SHELL_STATE_MOVING) {
		CAnimations* animations = CAnimations::GetInstance();
		animations->Get(ID_ANI_KOOPA_SHELL_ROTATE + direction + color)->Render(x,y);
	}
	else if (this->state == KOOPA_SHELL_STATE_SHAKE) {
		CAnimations* animations = CAnimations::GetInstance();
		animations->Get(ID_ANI_KOOPA_SHELL_SHAKE + direction + color)->Render(x, y);
	}
	else {
		CSprites* s = CSprites::GetInstance();
		s->Get(ID_SPRITE_KOOPA_SHELL + direction + color)->Draw(x, y);
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