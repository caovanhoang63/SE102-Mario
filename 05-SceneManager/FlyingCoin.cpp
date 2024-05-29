#include "FlyingCoin.h"



CFlyingCoin::CFlyingCoin(float x, float y) : CCoin(x, y) {
	distance = FLYING_DISTANCE;
}

void CFlyingCoin::Render() {
		CAnimations* animations = CAnimations::GetInstance();
		animations->Get(ID_ANI_FLYING_COIN)->Render(x, y);
}


#define MIN_MOVE 1.0f

void CFlyingCoin::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {
	float speed = distance / FLYING_TIME;
	float s = speed * dt;
	s = max(MIN_MOVE, s);
	this->y -= s;
	distance -= s;
	if (distance <= 0) {
		isDeleted = true;
	}
}
