#pragma once
#include "GameObject.h"
#include "InvisibleBlock.h"
class CEnemy :	public CGameObject
{
protected:
	float ax, ay, left_border, right_border;
	bool has_border;
	CInvisibleBlock* block;
public:
	CEnemy(float x, float y,float lb,float rb) : CGameObject(x, y) {
		this->left_border = lb;
		this->right_border = rb;
		if (lb + rb != 0) {
			this->block = new CInvisibleBlock(lb,y);
			this->has_border = true;
		}
		else {

			this->has_border = false;
		}
	};
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {
		if (this->has_border) {
			if (vx > 0) {
				this->block->SetPosition(this->right_border, this->initY);
			}
			else if (vx < 0) {
				this->block->SetPosition(this->left_border, this->initY);
			}
		}
	};
};

