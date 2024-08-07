#pragma once
#include "Enemy.h"
#include "KoopaShell.h"
#include "InvisibleBlock.h"

#define KOOPA_GRAVITY 0.0005f
#define KOOPA_WALKING_SPEED 0.05f

#define KOOPA_COLOR_RED 0
#define KOOPA_COLOR_GREEN	1000

#define ID_ANI_KOOPA_WALKING_LEFT	130000
#define ID_ANI_KOOPA_WALKING_RIGHT	130100

#define KOOPA_STATE_WALKING_LEFT 0
#define KOOPA_STATE_WALKING_RIGHT 100
#define KOOPA_STATE_DIE 999

#define KOOPA_BBOX_WIDTH	16
#define KOOPA_BBOX_HEIGHT	24

#define KOOPA_IN_SHELL_TIME 10000

#define KOOPA_SCORE 100


class CKoopa : public CEnemy
{
protected:
	CKoopaShell* shell;
	float ax,ay,width,height;
	int color;
	CInvisibleBlock* block;
	bool is_in_shell;
	ULONGLONG in_shell_start;
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
	virtual void Hitted(int nx);
	virtual void Pressed();
	virtual bool IsInStateDie();
	virtual void SetState(int state);
	virtual void EnterShell(int direction);
	virtual void ExitShell();
};


