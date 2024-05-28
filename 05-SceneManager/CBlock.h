#pragma once
#include "GameObject.h"
class CBlock :
    public CGameObject
{
protected:
	int width, height, idSprite;
public:
	CBlock(float x, float y,int width,int height,int idSprite );
	void Render();
	void Update(DWORD dt) {}
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	int IsBlocking() { return 1; }
};

