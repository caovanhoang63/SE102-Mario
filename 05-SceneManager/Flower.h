#pragma once
#include "GameObject.h"

#define ID_ANI_TOP 101000
#define ID_ANI_TOP_MOVE 101001
#define ID_ANI_BOTTOM_LEFT 102000 
#define ID_ANI_BOTTOM_LEFT_MOVE 102001
#define ID_ANI_TOP_LEFT 103000
#define ID_ANI_TOP_LEFT_MOVE 103001
#define ID_ANI_BOTTOM_RIGHT 104000
#define ID_ANI_TOP_RIGHT 105001
#define ID_ANI_TOP_RIGHT_MOVE 105001

#define FLOWER_COLOR_RED 0
#define FLOWER_COLOR_GREEN 10000

#define FLOWER_STATE_BOTTOM_LEFT_UP 110
#define FLOWER_STATE_BOTTOM_LEFT_DOWN 120
#define FLOWER_STATE_BOTTOM_LEFT_STOP 130
#define FLOWER_STATE_TOP_LEFT_UP 210
#define FLOWER_STATE_TOP_LEFT_DOWN 220
#define FLOWER_STATE_TOP_LEFT_STOP 230
#define FLOWER_STATE_BOTTOM_RIGHT_UP 310
#define FLOWER_STATE_BOTTOM_RIGHT_DOWN 320
#define FLOWER_STATE_BOTTOM_RIGHT_STOP 330
#define FLOWER_STATE_TOP_RIGHT_UP 410
#define FLOWER_STATE_TOP_RIGHT_DOWN 420
#define FLOWER_STATE_TOP_RIGHT_STOP 430
#define FLOWER_STATE_TOP_UP 510
#define FLOWER_STATE_TOP_DOWN 520
#define FLOWER_STATE_TOP_STOP 530
#define FLOWER_STATE_HIDDEN 610


class CFlower : public CGameObject
{
protected: 
	int color,width,height;
public:
	CFlower(float x, float y,int  width,int height,int color);
	void Render();
	void Update(DWORD dt);
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	int IsBlocking() { return 1; }
	void Observe();
	virtual void SetState(int state);
};

