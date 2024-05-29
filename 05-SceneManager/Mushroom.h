#pragma once
#include "GameObject.h"

#define ID_SPRITE_MUSHROOM 120000
#define MUSHROOM_SPEED_X 0.05f
#define MUSHROOM_SPEED_Y -0.01f
#define MUSHROOM_GRAVITY 0.002f
#define MUSHROOM_BBOX_WIDTH 16
#define MUSHROOM_BBOX_HEIGHT 16

#define MUSHROOM_STATE_RAISING 100
#define MUSHROOM_STATE_WALKING 200


class CMushroom :
    public CGameObject
{
protected:
	float ax, ay;
public:
	CMushroom(float x, float y);
	void Render();
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	void OnNoCollision(DWORD dt) ;
	void StopRaising();
	void OnCollisionWith(LPCOLLISIONEVENT e);
	virtual int IsCollidable() { return 1; };
	virtual int IsBlocking() { return 0; }
};

 