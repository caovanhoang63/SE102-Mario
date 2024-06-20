#include "Enemy.h"
#include "PlayScene.h"
#include "ScoreEffect.h"

CEnemy::CEnemy(float x, float y) : CGameObject(x, y) {
	isHitted = false;
	isPressed = false;
	score = 100;
	ax = 0;
	ay = 0;
};

void CEnemy::OnCollisionWith(LPCOLLISIONEVENT e) {
}

void CEnemy::Pressed()
{
	this->isHitted = false;
	this->isPressed = true; 
	
}

void CEnemy::Hitted(int nx)
{
	this->isHitted = nx;
	this->isPressed = false;
	this->vy = -ENEMY_DEFLECT_SPEED_Y; 
	if (score != 0) {
		CScoreEffect* score = new CScoreEffect(this->x, this->y, this->score);
		score->StartEffect();
	}
}




void CEnemy::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {

};