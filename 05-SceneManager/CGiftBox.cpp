#include "CGiftBox.h"

CGiftBox::CGiftBox(float x, float y) : CGameObject(x, y) {
	this->SetState(GIFTBOX_STATE_CLOSED);
	vy = 0;
	ay = 0;
	initY = y;
	isMoving = false;
}


void CGiftBox::SetState(int state) {
	CGameObject::SetState(state);
}
void CGiftBox::StartMove() {
	vy = GIFTBOX_SPEED;
	ay = GIFTBOX_GRAVITY;
	isMoving = true;
}

void CGiftBox::GenerateGift() {
	if (dynamic_cast<CPlayScene*>(CGame::GetInstance()->GetCurrentScene())) {
		CPlayScene* scene = (CPlayScene*)CGame::GetInstance()->GetCurrentScene();

	}
}


void CGiftBox::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	if (this->GetState() == GIFTBOX_STATE_CLOSED)
		animations->Get(ID_ANI_GIFTBOX_CLOSED)->Render(x, y);
	else 
		animations->Get(ID_ANI_GIFTBOX_OPENED)->Render(x, y);
}

void CGiftBox::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects ) {
	if (isMoving) {
		vy += ay * dt;
		y += vy * dt;
	}
	if (y >= initY && isMoving) {
		DebugOut(L"STOPPP");
		y = initY;
		isMoving = false;
	}
	CCollision::GetInstance()->Process(this, dt, coObjects);
}


void CGiftBox::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - GIFTBOX_BBOX_WIDTH / 2;
	t = y - GIFTBOX_BBOX_HEIGHT / 2;
	r = l + GIFTBOX_BBOX_WIDTH;
	b = t + GIFTBOX_BBOX_HEIGHT;
}

