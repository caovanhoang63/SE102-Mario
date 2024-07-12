#pragma once
#include "GameObject.h"


#define ANI_ID_FLOWER_NO_FIRE 230000

#define FLOWER_COLOR_RED 0
#define FLOWER_COLOR_GREEN 1000


#define FLOWER_STATE_STOP 0
#define FLOWER_STATE_REST 1
#define FLOWER_STATE_DOWN 2
#define FLOWER_STATE_UP 3

#define FLOWER_MOVING_DISTANCE 16
#define FLOWER_SPEED_Y 0.02
#define REST_TIME 500



class CFlowerNoFire : public CGameObject
{
protected:
	int color, width, height;
	ULONGLONG  rest_start;
	bool isRest = false;
public:
	CFlowerNoFire(float x, float y, int  width, int height, int color);
	void Render();
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	void StartRestTime() { isRest = true, rest_start = GetTickCount64(); }
	int IsBlocking() { return 1; }
	virtual void SetState(int state);
};

