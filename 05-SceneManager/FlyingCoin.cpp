#include "FlyingCoin.h"



//CFlyingCoin::CFlyingCoin(float x, float y) : CCoin(x, y) {
//	distance = FLYING_DISTANCE;
//}
//
//void CFlyingCoin::Render() {
//	CAnimations* animations = CAnimations::GetInstance();
//	animations->Get(ID_ANI_FLYING_COIN)->Render(x, y);
//
//}
//void CFlyingCoin::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {
//	float speed = distance / FLYING_TIME;
//	float s = speed * dt;
//	this->y -= s;
//	distance = s;
//	if (distance <= 0) {
//		isDeleted = true;
//	}
//}
