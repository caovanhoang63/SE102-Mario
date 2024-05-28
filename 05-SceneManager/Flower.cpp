#include "Flower.h"
#include "Game.h"

CFlower::CFlower(float x, float y, int  width, int height, int color) : CGameObject (x,y) {
	this->width = width;
	this->height = height;
	this->color = color;
	this->SetState(FLOWER_STATE_TOP_STOP);
}

void CFlower::Render() {
	CAnimations* animations = CAnimations::GetInstance();
	int ani = 0;
	switch (this->GetState())
	{
	case FLOWER_STATE_TOP_STOP: {
		ani = ID_ANI_TOP_LEFT_MOVE + this->color;
		break;
	}
	//case FLOWER_STATE_TOP_UP: {
	//	ani = ID_ANI_TOP_MOVE + this->color;
	//	break;
	//}
	default:
		break;
	}

	if (this->GetState() != FLOWER_STATE_HIDDEN) {
		animations->Get(ani)->Render(x, y);
	}
}


void CFlower::Observe() {
	float cx, cy;
	CGame::GetInstance()->GetCamPos(cx, cy);
	



}


void CFlower::Update(DWORD dt) {


}


void CFlower::SetState(int state) {
	CGameObject::SetState(state);
}


void CFlower::GetBoundingBox(float& l, float& t, float& r, float& b) {
	l = x - this->width / 2;
	t = y - this->height / 2;
	r = l + this->width;
	b = t + this->height;
}