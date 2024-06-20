#include "ScoreEffect.h"

CScoreEffect::CScoreEffect(float x, float y,int score ) : CEffect(x,y,0)
{
	this->vx = 0;
	this->vy = -SCORE_EFFECT_SPEED_Y;
	this->effectTime = SCORE_EFFECT_TIME;
	this->score = score;
	this->AniId = SCORE_EFFECT_BASE_ANI_ID + score;
	IncScore();
}

void CScoreEffect::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	x += vx * dt;
	y += vy * dt;
	CEffect::Update(dt, coObjects);
}

void CScoreEffect::IncScore()
{
	CPlayScene* scene = dynamic_cast<CPlayScene*>(CGame::GetInstance()->GetCurrentScene());
	CMario* mario = (CMario*)(scene->GetPlayer());
	mario->IncScore(score);
}
