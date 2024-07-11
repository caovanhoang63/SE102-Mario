#pragma once
#include "GameObject.h"

class CBackground : public CGameObject {
protected:
	int Width, Height, IdSprite;
public:
	CBackground(float x, float y, int Width, int Height, int  IdSprite) : CGameObject(x, y) {
		this->Width = Width;
		this->Height = Height;
		this->IdSprite = IdSprite;
	}
	void Render();
	void Update(DWORD dt) {}
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	int IsBlocking() { return 0; }
};
