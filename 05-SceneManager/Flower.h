#pragma once
#include "GameObject.h"
#include "Game.h"
#include <math.h>
#include "debug.h"
#include "Mario.h"
#include "FireBullet.h"
#include "PlayScene.h"
#include "Scene.h"


#define ANI_BASE_KEY 100000
#define ID_ANI_TOP 101000
#define ID_ANI_TOP_MOVE 101001
#define ID_ANI_BOTTOM_LEFT 102000 
#define ID_ANI_BOTTOM_LEFT_MOVE 102001
#define ID_ANI_TOP_LEFT 103000
#define ID_ANI_TOP_LEFT_MOVE 103001
#define ID_ANI_BOTTOM_RIGHT 104000
#define ID_ANI_TOP_RIGHT 105001
#define ID_ANI_TOP_RIGHT_MOVE 105001

#define FLOWER_MOVING_TIME 1000

#define FLOWER_HEAD_HIGHT_GAP 1

#define ATTACK_TIME 500
#define REST_TIME 500


#define FLOWER_COLOR_RED 0
#define FLOWER_COLOR_GREEN 10000

#define FLOWER_DIRECTION_TOP 1000
#define FLOWER_DIRECTION_BOTTOM_LEFT 2000
#define FLOWER_DIRECTION_TOP_LEFT 3000
#define FLOWER_DIRECTION_BOTTOM_RIGHT 4000
#define FLOWER_DIRECTION_TOP_RIGHT 5000

#define FLOWER_STATE_DOWN 2
#define FLOWER_STATE_HIDDEN -100
#define FLOWER_STATE_UP 1
#define FLOWER_STATE_STOP 0

class CFlower : public CGameObject
{
protected: 
	int color,width,height,direction;
	ULONGLONG attack_start,rest_start;
	bool isRest = false ;
	CMario* Mario;
public:
	CFlower(float x, float y,int  width,int height,int color, CMario* Mario);
	void Render();
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	void StartAttack() { attack_start = GetTickCount64(); }
	void StartRestTime() { isRest = true  ,rest_start = GetTickCount64(); }
	int IsBlocking() { return 1; }
	virtual void Observe();
	virtual void Attack(vector<LPGAMEOBJECT>* coObjects);
	virtual void SetState(int state);
};

