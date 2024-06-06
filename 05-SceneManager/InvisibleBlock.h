#pragma once
#include "GameObject.h"

#define INVISIBLEBLOCK_BBOX_WIDTH 16
#define INVISIBLEBLOCK_BBOX_HEIGHT 16

class CInvisibleBlock :
    public CGameObject
{
protected:
	int width, height;
public:
	CInvisibleBlock(float x, float  y);
	virtual void SetPosition(float x, float y);
	virtual void Render();
	virtual void Update(DWORD dt) {};
	virtual void GetBoundingBox(float& l, float& t, float& r, float& b);
	virtual int IsBlocking() { return 0; }
	virtual int IsCollidable() { return 1; };
};

