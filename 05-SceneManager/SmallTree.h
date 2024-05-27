#pragma once

#include "GameObject.h"

#define ID_ANI_SMALL_TREE 10000
#define BRICK_WIDTH 16
#define BRICK_BBOX_WIDTH 16
#define BRICK_BBOX_HEIGHT 16
class CSmallTree : public CGameObject {
protected:
	int Width, Height, IdSprite;
public:
	CSmallTree(float x, float y,int Width,int Height,int  IdSprite) : CGameObject(x, y) {
		this->Width = Width;
		this->Height = Height;
		this->IdSprite = IdSprite;
	}
	void Render();
	void Update(DWORD dt) {}
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	int IsBlocking() { return 0; }
};

typedef CSmallTree* LPSMALLTREE;