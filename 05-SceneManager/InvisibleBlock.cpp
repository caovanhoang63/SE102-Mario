#include "InvisibleBlock.h"


CInvisibleBlock::CInvisibleBlock(float x, float y) : CGameObject(x, y) {
	this->width = INVISIBLEBLOCK_BBOX_HEIGHT;
	this->height = INVISIBLEBLOCK_BBOX_HEIGHT;
}
void CInvisibleBlock::SetPosition(float x, float y) { this->x = x, this->y = y; }
void CInvisibleBlock::Render() {
	RenderBoundingBox();
}

void CInvisibleBlock::GetBoundingBox(float& l, float& t, float& r, float& b) {
	l = x - INVISIBLEBLOCK_BBOX_HEIGHT / 2;
	t = y - INVISIBLEBLOCK_BBOX_HEIGHT / 2;
	r = l + INVISIBLEBLOCK_BBOX_WIDTH;
	b = t + INVISIBLEBLOCK_BBOX_HEIGHT;
}

