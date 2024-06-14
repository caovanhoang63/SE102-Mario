#include "FlyingCoin.h"



CFlyingCoin::CFlyingCoin(float x, float y) : CCoin(x, y) {
	this->ax = 0;
	this->ay = FLYING_COIN_GRAVITY;
	this->vx = 0;
	this->vy = -FlYING_COIN_SPEED_Y;
}

void CFlyingCoin::Render() {
		CAnimations* animations = CAnimations::GetInstance();
		animations->Get(ID_ANI_FLYING_COIN)->Render(x, y);
}


void CFlyingCoin::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {
	vx += ax *dt;
	vy += ay * dt;
	x += vx * dt;
	y += vy * dt;
	if (this->y > this->initY) {
		this->isDeleted = true;
	}

}
