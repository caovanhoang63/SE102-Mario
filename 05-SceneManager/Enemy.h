#pragma once
#include "GameObject.h"
#include "InvisibleBlock.h"

class CEnemy :	public CGameObject
{
protected:
	float ax, ay;
	bool isPressed;
	int isHitted;

public:
	CEnemy(float x, float y);
	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom) = 0;
	virtual void Render() = 0;
	virtual void SetState(int state) { this->state = state; }
	virtual int IsCollidable() { return 0; };
	virtual void OnNoCollision(DWORD dt) {};
	virtual void OnCollisionWith(LPCOLLISIONEVENT e);
	virtual void Pressed() { this->isHitted = false;  this->isPressed = true; }
	virtual void Hitted(int nx) { this->isHitted = nx; this->isPressed = false; }
	virtual bool IsInStateDie() = 0;
	virtual int IsBlocking() { return 1; }
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
};

