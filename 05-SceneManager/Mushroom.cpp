#include "Mushroom.h"


CMushroom::CMushroom(float x, float y) : CGameObject(x, y) {
	ax = 0;
	ay = 0;
	this->state = MUSHROOM_STATE_RAISING;
	this->vy = MUSHROOM_SPEED_Y;
}



void CMushroom::Render() {
	CSprites* s = CSprites::GetInstance();
	s->Get(ID_SPRITE_MUSHROOM)->Draw(x, y);
}


void CMushroom::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {
	vy += ay * dt;
	vx += ax * dt;
	if (this->y <= this->initY - 16 && this->state == MUSHROOM_STATE_RAISING) {
		this->y = this->initY - 16;
		StopRaising();
	}
	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}

void CMushroom::GetBoundingBox(float& l, float& t, float& r, float& b) {
	l = x - MUSHROOM_BBOX_WIDTH / 2;
	t = y - MUSHROOM_BBOX_HEIGHT / 2;
	r = l + MUSHROOM_BBOX_WIDTH;
	b = t + MUSHROOM_BBOX_HEIGHT;
}


void CMushroom::StopRaising() {
	this->vy = 0;
	this->ay = MUSHROOM_GRAVITY;
	this->vx = MUSHROOM_SPEED_X;
	this->state = MUSHROOM_STATE_WALKING;
}


void CMushroom::OnNoCollision(DWORD dt)
{
	y += vy * dt;
	x += vx * dt;
};

void CMushroom::OnCollisionWith(LPCOLLISIONEVENT e)
{
	DebugOut(L"OK");
	if (this->state == MUSHROOM_STATE_RAISING) return;
	if (!e->obj->IsBlocking()) return;
	if (dynamic_cast<CMushroom*>(e->obj)) return;
	if (e->ny != 0)
	{
		vy = 0;
	}
	else if (e->nx != 0)
	{
		vx = -vx;
	}
}