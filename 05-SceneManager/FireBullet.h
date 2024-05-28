#pragma once
#include "GameObject.h"
#include "math.h"
#include "debug.h"


#define ID_ANI_FIRE_BULLET 110000
#define FIRE_BULLET_BBOX_WIDTH 8
#define FIRE_BULLET_BBOX_HEIGHT 8

#define FIRE_BULLET_SPEED 0.2f
# define M_PI	3.14159265358979323846 

#define DIRECTION_1 (M_PI/6.f)
#define DIRECTION_2 (M_PI/3.f)
#define DIRECTION_3 (2*M_PI/3.f)
#define DIRECTION_4 (5*M_PI/6.f)
#define DIRECTION_5 (7*M_PI/6.f)
#define DIRECTION_6 (4*M_PI/3.f)
#define DIRECTION_7 (5*M_PI/3.f)
#define DIRECTION_8 (11*M_PI/6.f)

class CFireBullet :
    public CGameObject
{
protected : 
	LPGAMEOBJECT target;
	float direction;
public :
	CFireBullet(float x, float y, LPGAMEOBJECT target);
	void FindDirection();
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void Render();
	void Update(DWORD dt) {}
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	int IsBlocking() { return 1; }
};

