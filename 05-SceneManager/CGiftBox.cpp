#include "CGiftBox.h"

CGiftBox::CGiftBox(float x, float y) : CGameObject(x, y) {
	this->SetState(GIFTBOX_STATE_CLOSED);
}


void CGiftBox::SetState(int state) {
	CGameObject::SetState(state);
}



void CGiftBox::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	if (this->GetState() == GIFTBOX_STATE_CLOSED)
		animations->Get(ID_ANI_GIFTBOX_CLOSED)->Render(x, y);
	else 
		animations->Get(ID_ANI_GIFTBOX_OPENED)->Render(x, y);
}

void CGiftBox::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - GIFTBOX_BBOX_WIDTH / 2;
	t = y - GIFTBOX_BBOX_HEIGHT / 2;
	r = l + GIFTBOX_BBOX_WIDTH;
	b = t + GIFTBOX_BBOX_HEIGHT;
}

