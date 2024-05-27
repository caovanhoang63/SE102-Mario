#pragma once
#include "GameObject.h"

#define ID_ANI_GIFTBOX 80000
#define GIFTBOX_WIDTH 16
#define GIFTBOX_BBOX_WIDTH 16
#define GIFTBOX_BBOX_HEIGHT 16


class CGiftBox : public CGameObject
{
public:
	CGiftBox(float x, float y) : CGameObject(x, y){}
	void Render();
	void Update(DWORD dt) {}
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	int IsBlocking() { return 1; }
};


