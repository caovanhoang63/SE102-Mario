#pragma once
#include "Effect.h"

#define SCORE_EFFECT_TIME 500
#define SCORE_EFFECT_SPEED_Y 0.1f
#define SCORE_EFFECT_BASE_ANI_ID 170000
const int  SCORES[8]{ 100,200,400,800,1000,2000,4000,8000 };



class CScoreEffect :
    public CEffect
{
protected: 
    int score;
public: 
    CScoreEffect(float x, float y, int AniId);
    virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
    virtual void IncScore();
};

