#pragma once
#include "GameObject.h"
#include "PlayScene.h"
class CEffect :
    public CGameObject
{
protected:
    ULONGLONG effectTime, effectStartTime;  
    int AniId;
  
public:
    CEffect(float x, float y, int AniId);
    virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
    virtual void Render();
    virtual void StartEffect();
    virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom) {};
    virtual int IsCollidable() { return 0; };
    virtual int IsBlocking() { return 0; }
};

