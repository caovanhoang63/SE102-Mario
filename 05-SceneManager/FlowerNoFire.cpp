#include "FlowerNoFire.h"


void CFlowerNoFire::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	int aniID = ANI_ID_FLOWER_NO_FIRE + this->color;
	animations->Get(aniID)->Render(x, y);
}


CFlowerNoFire::CFlowerNoFire(float x, float y, int width, int height, int color) : CGameObject(x, y)

{
	this->initY = y;
	this->width = width;
	this->height = height;
	this->color = color;
	this->rest_start = -1;
	this->SetState(FLOWER_STATE_REST);
}

void CFlowerNoFire::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	x += vx * dt ;
	y += vy * dt ;
	if (this->state == FLOWER_STATE_REST && GetTickCount64() - rest_start > REST_TIME)
	{
		 this->SetState(FLOWER_STATE_UP);
	} else if (this->state == FLOWER_STATE_STOP && GetTickCount64() - rest_start > REST_TIME)
	{
		this->SetState(FLOWER_STATE_DOWN);
	} else if (this->state == FLOWER_STATE_UP && y <= initY - this->height)
	{
		this->SetState(FLOWER_STATE_STOP);

	} else if (this->state == FLOWER_STATE_DOWN && y >= initY)
	{
		this->SetState(FLOWER_STATE_REST);
	}
	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);

}

void CFlowerNoFire::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - this->width / 2;
	t = y - this->height / 2;
	r = l + this->width;
	b = t + this->height;
}

void CFlowerNoFire::SetState(int state)
{
	CGameObject::SetState(state);
	switch (state)
	{
	case FLOWER_STATE_STOP: {
		this->vy = 0;
		this->y = initY - this->height;
		this->StartRestTime();

		break;
	}
	case FLOWER_STATE_REST: {
		this->vy = 0;
		this->y = initY;
		this->StartRestTime();
		break;
	}
	case FLOWER_STATE_UP: {
		this->vy = -FLOWER_SPEED_Y;
		rest_start = 0;
		isRest = false;
		break;
	}
	case FLOWER_STATE_DOWN: {
		this->vy = FLOWER_SPEED_Y;
		rest_start = 0;
		isRest = false;
		break;
	}
	default:
		break;
	}

}
