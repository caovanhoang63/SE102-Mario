#include "Enemy.h"
#include "PlayScene.h"
#include "ScoreEffect.h"

CEnemy::CEnemy(float x, float y) : CGameObject(x, y) {
	isHitted = false;
	isPressed = false;
	score = 0;
	ax = 0;
	ay = 0;
};

void CEnemy::OnCollisionWith(LPCOLLISIONEVENT e) {
}

void CEnemy::Pressed()
{
	this->isHitted = false;
	this->isPressed = true; 
	if (score != 0) {
		CScoreEffect* score = new CScoreEffect(this->x, this->y, this->score);
		score->StartEffect();
	}
}




void CEnemy::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {

};