#include "CBlock.h"



CBlock::CBlock(float x, float y, int width, int height, int idSprite) : CGameObject(x, y) {
	this->idSprite = idSprite;
	this->width = width;
	this->height = height;
}

void CBlock::Render() {
	CSprites* s = CSprites::GetInstance();
	s->Get(this->idSprite)->Draw(x, y);
};



void CBlock::GetBoundingBox(float& l, float& t, float& r, float& b) {
	l = x - this->width / 2;
	t = y - this->height / 2;
	r = l + this->width;
	b = t + this->height;
}

void CBlockUpdate(DWORD dt) {


};
