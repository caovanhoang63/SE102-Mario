#include "Enemy.h"
#include "PlayScene.h"

CEnemy::CEnemy(float x, float y) : CGameObject(x, y) {
	
};

void CEnemy::OnCollisionWith(LPCOLLISIONEVENT e) {
}


void CEnemy::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {

};