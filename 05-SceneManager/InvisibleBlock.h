#pragma once
#include "GameObject.h"

#define INVISIBLEBLOCK_BBOX_WIDTH 4
#define INVISIBLEBLOCK_BBOX_HEIGHT 4
#define INVISIBLEBLOCK_KOOPA_X_OFFSET 10
#define INVISIBLEBLOCK_KOOPA_Y_OFFSET 6
#define INVISIBLEBLOCK_GRAVITY 0.02f
#define INVISIBLEBLOCK_SPEED_X 0.05f

class CInvisibleBlock :
    public CGameObject
{
protected:
	int width, height;
	float ax, ay;
	bool is_on_platform;
public:
	CInvisibleBlock(float x, float  y) ;
	virtual void SetPosition(float x, float y);
	virtual void Render();
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	void SetToLeft(float x,float y);
	void SetToRight(float x,float y);
	virtual void OnNoCollision(DWORD dt);
	virtual void OnCollisionWith(LPCOLLISIONEVENT e);
	virtual int IsBlocking() { return 0; }
	virtual int IsCollidable() { return 1; };
	bool isOnPlatform(){
		return is_on_platform;
	};
};

