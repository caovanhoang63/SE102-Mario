#pragma once
#include "Coin.h"

#define ID_ANI_FLYING_COIN 12000
#define FlYING_COIN_SPEED_Y 0.35f
#define FLYING_COIN_GRAVITY 0.001f


class CFlyingCoin :public CCoin
{
protected:
	float ax, ay;
public:
	CFlyingCoin(float x, float y);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects );
	virtual void Render();
};

