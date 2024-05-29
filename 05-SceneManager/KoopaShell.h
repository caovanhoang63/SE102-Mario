#pragma once
#include "GameObject.h"

#define KOOPA_SHELL_SPEED 0.5f
#define KOOPA_AX 0.02f
#define KOOPA_SHELL_GRAVITY 0.02f

#define ID_ANI_KOOPA_SHELL_ROTATE  130010
#define ID_SPRITE_KOOPA_SHELL   130010

#define ID_KOOPA_SHELL_COLOR_RED 0
#define ID_KOOPA_SHELL_COLOR_GREEN 0

#define KOOPA_SHELL_STATE_STOP  0
#define KOOPA_SHELL_STATE_MOVING 100


#define KOOPA_SHELL_BBOX_WIDTH	16
#define KOOPA_SHELL_BBOX_HEIGHT	16

class CKoopaShell :
    public CGameObject
{
protected:
    float ax, ay;
	int color; 
public:
    CKoopaShell(float x, float y, int color);
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void Render();
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	void StartMove(float x);
	virtual void OnNoCollision(DWORD dt);
	virtual void OnCollisionWith(LPCOLLISIONEVENT e);
	int IsBlocking() { return 1; }
};

