#include "Brick.h"

#include "KoopaShell.h"
#include "PlayScene.h"
#include "Coin.h"

void CBrick::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	animations->Get(ID_ANI_BRICK)->Render(x, y);
}

void CBrick::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}

void CBrick::OnCollisionWith(LPCOLLISIONEVENT e)
{
	if (dynamic_cast<CKoopaShell*>(e->obj))  {
		CKoopaShell* shell = dynamic_cast<CKoopaShell*>(e->obj);
		if (shell->GetState() == KOOPA_SHELL_STATE_MOVING) {
			float vx, vy;
			shell->GetSpeed(vx, vy);
			shell->SetSpeed(-vx, vy);
			this->Delete();
		}
	}
}

void CBrick::GetBoundingBox(float &l, float &t, float &r, float &b)
{
	l = x - BRICK_BBOX_WIDTH/2;
	t = y - BRICK_BBOX_HEIGHT/2;
	r = l + BRICK_BBOX_WIDTH;
	b = t + BRICK_BBOX_HEIGHT;
}

void CBrick::Hitted()
{
	this->Delete();
}

void CBrick::ToCoin()
{
	CPlayScene* scene = dynamic_cast<CPlayScene*>(CGame::GetInstance()->GetCurrentScene());
	scene->AddNewObjectToTail(new CCoin(x,y));
	this->Delete();
}
