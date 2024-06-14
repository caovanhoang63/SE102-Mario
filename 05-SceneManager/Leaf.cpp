#include "Leaf.h"

CLeaf::CLeaf(float x, float y) : CGameObject(x,y)
{
	this->vx = 0;
	this->vy = -LEAF_SPEED_Y;
	this->ax = 0;
	this->ay = LEAF_GRAVITY;

}

void CLeaf::Render()
{
	CSprites* sprites = CSprites::GetInstance();
	if (this->vx <= 0)
		sprites->Get(ID_SPRITE_LEAF_LEFT)->Draw(x, y);
	else 
		sprites->Get(ID_SPRITE_LEAF_RIGHT)->Draw(x, y);
}

void CLeaf::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	vx += ax * dt;
	vy += ay * dt;
	DebugOut(L"ACCEL: %f\n", ax);
	DebugOut(L"SPEED: %f\n", vx);
	if (this->vy >= 0 && ay != 0) {
		this->vx = LEAF_SPEED_X;
		this->ax = LEAF_ACCEL_X;
		this->vy = LEAF_FALL_SPEED;
		this->ay = 0;
	}
	else if (abs(this->vx) >= LEAF_SPEED_X_MAX && ay == 0) {
		if (this->ax > 0) {
			this->vx = -LEAF_SPEED_X;
		}
		else {
			this->vx = +LEAF_SPEED_X;
		}
		this->ax = -ax;
	}

	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);

	x += vx * dt;
	y += vy * dt;
}

void CLeaf::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - LEAF_BBOX_WIDTH / 2;
	t = y - LEAF_BBOX_HEIGHT / 2;
	r = l + LEAF_BBOX_WIDTH;
	b = t + LEAF_BBOX_HEIGHT;
}
