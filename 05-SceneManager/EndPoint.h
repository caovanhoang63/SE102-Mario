#pragma once
#include "GameObject.h"

#define ID_SPRITE_END_POINT 290000
#define END_POINT_WIDTH 16
#define END_POINT_HEIGHT 16

class CEndPoint :public CGameObject
{
public:
	CEndPoint(float x, float y) : CGameObject(x, y) {
	
	}
	void Render() {
		CAnimations* animations = CAnimations::GetInstance();
		animations->Get(ID_SPRITE_END_POINT)->Render(x, y);
	}
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects ) {
		CGameObject::Update(dt,coObjects);
		CCollision::GetInstance()->Process(this, dt, coObjects);
	};

	void GetBoundingBox(float& l, float& t, float& r, float& b) {
		l = x - END_POINT_WIDTH / 2;
		t = y - END_POINT_HEIGHT / 2;
		r = l + END_POINT_WIDTH;
		b = t + END_POINT_HEIGHT;
	}
	int IsBlocking() { return 1; }
	virtual int IsCollidable() { return 1; };
};

