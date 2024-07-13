#include "InvisibleBlock.h"


CInvisibleBlock::CInvisibleBlock(float x, float y) : CGameObject(x - INVISIBLEBLOCK_KOOPA_X_OFFSET, y + INVISIBLEBLOCK_KOOPA_X_OFFSET) {
	this->width = INVISIBLEBLOCK_BBOX_HEIGHT;
	this->height = INVISIBLEBLOCK_BBOX_HEIGHT;
	this->ax = 0;
	this->ay = INVISIBLEBLOCK_GRAVITY;
	this->is_on_platform = true;
}

void CInvisibleBlock::OnNoCollision(DWORD dt) {
	x += vx * dt;
	y += vy * dt;
}

void CInvisibleBlock::OnCollisionWith(LPCOLLISIONEVENT e) {
	if (!e->obj->IsBlocking()) return;
	if (e->ny != 0)
	{
		vy = 0;
		this->is_on_platform = true;
	}
}


void CInvisibleBlock::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {
	vx += ax * dt;
	vy += ay * dt;
	if (this->vy > 0) {
		this->is_on_platform = false;
	}

	CCollision::GetInstance()->Process(this, dt, coObjects);
};


void CInvisibleBlock::SetPosition(float x, float y) { this->x = x, this->y = y; }

void CInvisibleBlock::Render() {
	//RenderBoundingBox();
}

void CInvisibleBlock::SetToLeft(float x,float y ) {
	this->SetPosition(x - INVISIBLEBLOCK_KOOPA_X_OFFSET, y + INVISIBLEBLOCK_KOOPA_X_OFFSET);
}

void CInvisibleBlock::SetToRight(float x,float y ) {
	this->SetPosition(x + INVISIBLEBLOCK_KOOPA_X_OFFSET, y + INVISIBLEBLOCK_KOOPA_X_OFFSET);
}


void CInvisibleBlock::GetBoundingBox(float& l, float& t, float& r, float& b) {
	l = x - INVISIBLEBLOCK_BBOX_HEIGHT / 2;
	t = y - INVISIBLEBLOCK_BBOX_HEIGHT / 2;
	r = l + INVISIBLEBLOCK_BBOX_WIDTH;
	b = t + INVISIBLEBLOCK_BBOX_HEIGHT;
}

