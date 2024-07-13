#pragma once
#include "Brick.h"

#define ID_ANI_EMPTY_BRICK 84000

class CSpecialBrick :public CBrick
{
protected:
	bool isCollision;

public:
	CSpecialBrick(float x, float y) :CBrick(x, y) {
		isCollision = false;
	}
	virtual void Hitted();
	virtual void GenButton();
	virtual void OnCollisionWith(LPCOLLISIONEVENT e);
	virtual void Render();
	void ToCoin() { };
};

