#pragma once
#include "GameObject.h"

#define ID_SPRITE_LEAF_LEFT	150000
#define ID_SPRITE_LEAF_RIGHT	150001

#define LEAF_SPEED_X_MAX 0.15f 
#define LEAF_SPEED_X	0.08f
#define LEAF_SPEED_Y	0.3f
#define LEAF_FALL_SPEED 0.03


#define LEAF_GRAVITY	0.001f
#define LEAF_ACCEL_X	0.00015f

#define LEAF_BBOX_WIDTH 16
#define LEAF_BBOX_HEIGHT 14

class CLeaf :
    public CGameObject
{
protected:
	float ax, ay;
	virtual int IsCollidable() { return 1; };
	virtual int IsBlocking() { return 0; }
public:
	CLeaf(float x, float y);
	virtual void Render();
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects );
	virtual void GetBoundingBox(float& l, float& t, float& r, float& b);
	//int IsBlocking() { return 0; }
};

