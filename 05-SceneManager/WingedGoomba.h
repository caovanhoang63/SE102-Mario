#pragma once
#include "Goomba.h"


#define WINGED_GOOMBA_DIE_TIMEOUT 500
#define WINGED_GOOMBA_WALKING_TIME 3000
#define WINGEG_GOOMBA_NUM_OF_JUMP 3

#define WINGED_GOOMBA_SPEED_JUMP_Y	0.2f
#define WINGED_GOOMBA_SPEED_HIGH_JUMP_Y	0.3f

#define WINGED_GOOMBA_STATE_WALKING 100
#define WINGED_GOOMBA_STATE_JUMP 200
#define WINGED_GOOMBA_STATE_HIGH_JUMP 300
#define WINGED_GOOMBA_STATE_NO_WINGS_WALKING 400
#define WINGED_GOOMBA_STATE_DIE 500


#define ID_ANI_WINGED_GOOMBA_WALKING 140001
#define ID_ANI_WINGED_GOOMBA_JUMP 140002
#define ID_ANI_WINGED_GOOMBA_HIGH_JUMP 140003
#define ID_ANI_WINGED_GOOMBA_NO_WINGS_WALKING 140004
#define ID_ANI_WINGED_DIE 149999

class CWingedGoomba :
    public CGoomba
{
protected:
	bool isOnPlatform;
	int jumpCount;
	ULONGLONG die_start,walking_start;

	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void Render();
	virtual void OnCollisionWith(LPCOLLISIONEVENT e);
public:
	CWingedGoomba(float x, float y);
	virtual void SetState(int state);

};

