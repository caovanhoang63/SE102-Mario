#pragma once
#include "Coin.h"

#define ID_ANI_FLYING_COIN 12000

#define FLYING_DISTANCE 40
#define FLYING_TIME 100

class CFlyingCoin :public CCoin
{
protected:
	float distance;
public:
	CFlyingCoin(float x, float y);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects = NULL);
	virtual void Render();
};

