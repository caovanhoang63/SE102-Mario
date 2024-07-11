#pragma once
#include "Koopa.h"



#define ID_ANI_WINGED_KOOPA_JUMP_LEFT	181000
#define ID_ANI_WINGED_KOOPA_JUMP_RIGHT	181100



#define WINGED_KOOPA_JUMP_SPEED 0.2f
#define WINGED_KOOPA_WALKING_SPEED 0.03f
#define WINGED_KOOPA_STATE_WALKING 100
#define WINGED_KOOPA_STATE_JUMP 200
#define WINGED_KOOPA_STATE_NO_WINGS_WALKING 300
#define WINGED_KOOPA_STATE_DIE 999


class CWingedKoopa : public CKoopa
{
protected:
	bool isOnPlatform;
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void OnCollisionWith(LPCOLLISIONEVENT e);
	virtual void OnNoCollision(DWORD dt);
	virtual int GetAniId();
	virtual void Render();
public:
	CWingedKoopa(float x, float y, int color) ;
	virtual void Hitted(int nx);
	virtual void Pressed();
	virtual bool IsInStateDie();
};

