#pragma once
#include "GameObject.h"
#define KOOPA_SHELL_SPEED 0.2f
#define KOOPA_SHELL_GRAVITY 0.001f
#define KOOPA_SHELL_DEFLECT_SPEED_Y 0.3f
#define KOOPA_SHELL_DEFLECT_SPEED_X 0.1f
#define KOOPA_SHELL_DEFLECT_ACCEL_X 0.0001f

#define ID_ANI_KOOPA_SHELL_ROTATE  130000
#define ID_SPRITE_KOOPA_SHELL   130000
#define ID_ANI_KOOPA_SHELL_SHAKE   130001

#define ID_KOOPA_SHELL_COLOR_RED 0
#define ID_KOOPA_SHELL_COLOR_GREEN 1000

#define KOOPA_SHELL_STATE_STOP  0
#define KOOPA_SHELL_STATE_MOVING 100
#define KOOPA_SHELL_STATE_SHAKE  200


#define KOOPA_SHELL_BBOX_WIDTH	16
#define KOOPA_SHELL_BBOX_HEIGHT	14

#define KOOPA_SHELL_SHAKE_STOP_TIME 3000


#define KOOPA_SHELL_DIRECTION_UP	10
#define KOOPA_SHELL_DIRECTION_DOWN	20

class CKoopaShell :
    public CGameObject
{
protected:
    float ax, ay;
	int color;
	int direction;
	bool isOnPlatform;
	bool isHittedDeflect;
	int hitCount;
	ULONGLONG stop_start;
public:
	CKoopaShell(float x, float y, int color, int direction);
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void Render();
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	void StartMove(float x);
	void StopMove() {
		this->state = KOOPA_SHELL_STATE_STOP;
		this->stop_start = GetTickCount64();
		this->vx = 0;
		this->hitCount = 0;
	}
	virtual void IncScore();
	virtual void Hitted(int nx);
	virtual void OnNoCollision(DWORD dt);
	virtual void OnCollisionWith(LPCOLLISIONEVENT e);
	virtual int IsCollidable() { return 1; };
	virtual int IsBlocking() { return 0; }
};

