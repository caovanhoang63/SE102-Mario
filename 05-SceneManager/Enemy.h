#pragma once
#include "GameObject.h"
#include "InvisibleBlock.h"


#define ENEMY_DEFLECT_SPEED_Y 0.3f
#define ENEMY_DEFLECT_SPEED_X 0.05f

class CEnemy :	public CGameObject
{
protected:
	float ax, ay;
	bool isPressed;
	int isHitted;
	int score;
public:
	CEnemy(float x, float y);
	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom) = 0;
	virtual void Render() = 0;
	virtual void SetState(int state) { this->state = state; }
	virtual int IsCollidable() { return 0; };
	virtual void OnNoCollision(DWORD dt) {};
	virtual void OnCollisionWith(LPCOLLISIONEVENT e);
	virtual void Pressed();
	virtual void Hitted(int nx);
	virtual bool IsInStateDie() = 0;
	virtual int IsBlocking() { return 1; }
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
};

