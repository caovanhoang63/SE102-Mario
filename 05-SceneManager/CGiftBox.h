#pragma once
#include "GameObject.h"
#include "Game.h"
#include "PlayScene.h"
#include "FlyingCoin.h"
#include "Mushroom.h"
#define ID_ANI_GIFTBOX_CLOSED 80000
#define ID_ANI_GIFTBOX_OPENED 84000
#define GIFTBOX_WIDTH 16
#define GIFTBOX_BBOX_WIDTH 16
#define GIFTBOX_BBOX_HEIGHT 16
#define GIFTBOX_STATE_CLOSED 100
#define GIFTBOX_STATE_OPENED 200

#define GIFTBOX_GRAVITY 0.005f
#define GIFTBOX_SPEED -0.5f



class CGiftBox : public CGameObject
{
protected:
	float ay,initY;
	bool isMoving,hasBuff;
public:
	CGiftBox(float x, float y,bool hasBuff);
	void Render();
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	int IsBlocking() { return 1; }
	virtual void SetState(int state);
	int IsCollidable() { return 1; };
	void StartMove();
	void GenerateGift();
	void GenerateBuff();
};


