#include "Spawner.h"
#include "Mario.h"
#include "PlayScene.h"

CSpawner::CSpawner(float x, float y) : CGameObject(x,y)
{
	this->isActive = true;
	this->width = SPAWNER_BBOX_WIDTH;
	this->height = SPAWNER_BBOX_HEIGHT;
	this->obj = vector<CGameObject*>();
}

void CSpawner::SetPosition(float x, float y)
{
	CGameObject::SetPosition(x, y);
}

void CSpawner::Render()
{
	RenderBoundingBox();	
}


void CSpawner::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	CGameObject::Update(dt,coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}

void CSpawner::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - this->width / 2;
	t = y - this->height / 2;
	r = l + this->width;
	b = t + this->height;
}

void CSpawner::OnCollisionWith(LPCOLLISIONEVENT e)
{
	if (dynamic_cast<CMario*>(e->obj)) {
		this->Spawn();
	}
}

void CSpawner::Spawn()
{
	if (!this->isActive) return;
	if (dynamic_cast<CPlayScene*>(CGame::GetInstance()->GetCurrentScene())) {
		CPlayScene* scene = (CPlayScene*)(CGame::GetInstance()->GetCurrentScene());
		for (int i = 0; i < this->obj.size(); i++) {
			scene->AddNewObjectToTail(obj[i]);
		}
	};
	this->isActive = false;
}
