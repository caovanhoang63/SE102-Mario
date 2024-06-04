#pragma once
#include "GameObject.h"
#include "KoopaShell.h"
#include "PlayScene.h"

#define KOOPA_GRAVITY 0.02f
#define KOOPA_WALKING_SPEED 0.05f

#define KOOPA_COLOR_RED 0
#define KOOPA_COLOR_GREEN	1000

#define ID_ANI_KOOPA_WALKING_LEFT	130000
#define ID_ANI_KOOPA_WALKING_RIGHT	130100

#define KOOPA_STATE_WALKING_LEFT 0
#define KOOPA_STATE_WALKING_RIGHT 100
#define KOOPA_STATE_DIE -100

#define KOOPA_BBOX_WIDTH	16
#define KOOPA_BBOX_HEIGHT	24

class CKoopa : public CGameObject
{
protected:
	float ax;
	float ay;
	int color;
	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void Render();
	virtual int IsCollidable() { return 1; };
	virtual int IsBlocking() { return 0; }
	virtual void OnNoCollision(DWORD dt);
	virtual void OnCollisionWith(LPCOLLISIONEVENT e);
	virtual int GetAniId();
public:
	CKoopa(float x, float y, int color);
	virtual void SetState(int state);
	virtual void Die();
};


