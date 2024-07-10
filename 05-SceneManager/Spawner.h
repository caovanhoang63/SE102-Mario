#pragma once
#include "GameObject.h"
#include "Enemy.h"
#include "AssetIDs.h"

#define SPAWNER_BBOX_WIDTH 16
#define SPAWNER_BBOX_HEIGHT 10000

class CSpawner : public CGameObject
{
protected:
	int width, height;
	bool isActive;
	vector<CGameObject*> obj;
public:
	CSpawner(float x, float  y);
	virtual void SetPosition(float x, float y);
	virtual void Render();
	void AddObject(CGameObject* obj) { this->obj.push_back(obj); }
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	virtual void OnCollisionWith(LPCOLLISIONEVENT e);
	virtual int IsBlocking() { return 0; }
	virtual int IsCollidable() { return 1; };
	void Spawn();
};



