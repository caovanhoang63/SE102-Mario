#pragma once
#include "GameObject.h"

#define ID_ANI_GIFTBOX_CLOSED 80000
#define ID_ANI_GIFTBOX_OPENED 84000
#define GIFTBOX_WIDTH 16
#define GIFTBOX_BBOX_WIDTH 16
#define GIFTBOX_BBOX_HEIGHT 16
#define GIFTBOX_STATE_CLOSED 100
#define GIFTBOX_STATE_OPENED 200





class CGiftBox : public CGameObject
{
public:
	CGiftBox(float x, float y);
	void Render();
	void Update(DWORD dt) {}
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	int IsBlocking() { return 1; }
	virtual void SetState(int state);

};


