#pragma once
#include "Goomba.h"


#define WINGED_GOOMBA_DIE_TIMEOUT 500
#define WINGED_GOOMBA_WALKING_TIME 2000
#define WINGEG_GOOMBA_NUM_OF_JUMP 3
#define WINGED_GOOMBA_OBSERVE_TIME 1000

#define WINGED_GOOMBA_BBOX_WIDTH 16
#define WINGED_GOOMBA_BBOX_HEIGHT 18
#define WINGED_GOOMBA_NO_WINGS_BBOX_HEIGHT 14
#define WINGED_GOOMBA_BBOX_HEIGHT_DIE 7


#define WINGED_GOOMBA_SPEED_JUMP_Y	0.1f
#define WINGED_GOOMBA_SPEED_HIGH_JUMP_Y	0.3f

#define WINGED_GOOMBA_STATE_WALKING 100
#define WINGED_GOOMBA_STATE_JUMP 200
#define WINGED_GOOMBA_STATE_HIGH_JUMP 300
#define WINGED_GOOMBA_STATE_NO_WINGS_WALKING 400
#define WINGED_GOOMBA_STATE_DIE 999


#define ID_ANI_WINGED_GOOMBA_WALKING 140001
#define ID_ANI_WINGED_GOOMBA_JUMP 140002
#define ID_ANI_WINGED_GOOMBA_HIGH_JUMP 140003
#define ID_ANI_WINGED_GOOMBA_NO_WINGS_WALKING 140004
#define ID_ANI_WINGED_GOOMBA_NO_WINGS_HITTED 140005
#define ID_ANI_WINGED_DIE 149999

class CWingedGoomba :
    public CGoomba
{
protected:
	bool isOnPlatform;
	int jumpCount;
	ULONGLONG die_start,walking_start,observe_start;
	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void Render();
	virtual void OnCollisionWith(LPCOLLISIONEVENT e);
	virtual void Observe();
public:
	CWingedGoomba(float x, float y);
	virtual void SetState(int state);
	virtual void Hitted(int nx);
	virtual void Pressed();
	virtual bool IsInStateDie();
};

