#pragma once
#include "GameObject.h"

#define SPRITE_SCOREBOARD		530000


class CScoreBoard : public CGameObject
{

public: 
	CScoreBoard(float x, float y) : CGameObject(x,y) {};
	void Render() {
		CSprites* s = CSprites::GetInstance();
		s->Get(SPRITE_SCOREBOARD)->Draw(x, y);
	}
	void Update(DWORD dt) {}
	void GetBoundingBox(float& l, float& t, float& r, float& b) {};
	int IsBlocking() { return 0; }
	virtual int IsCollidable() { return 0; };

};

