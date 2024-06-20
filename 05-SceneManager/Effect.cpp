#include "Effect.h"
#include "PlayScene.h"


CEffect::CEffect(float x, float y, int AniId) : CGameObject(x, y) {
    this->effectTime = 0;
    this->effectStartTime = -1 ;
    this->AniId = AniId;
}
void CEffect::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {
    if (effectStartTime != -1 &&  GetTickCount64() - effectStartTime > effectTime) {
        Delete();
    }
};

void CEffect::Render() {
    CAnimations* animations = CAnimations::GetInstance();
    animations->Get(AniId)->Render(x, y);
};


void CEffect::StartEffect()
{
    effectStartTime = GetTickCount64();
    dynamic_cast<CPlayScene*>(CGame::GetInstance()->GetCurrentScene())->AddNewObjectToTail(this);
}
