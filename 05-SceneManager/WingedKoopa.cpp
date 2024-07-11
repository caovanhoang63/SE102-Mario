#include "WingedKoopa.h"
#include "PlayScene.h"

CWingedKoopa::CWingedKoopa(float x, float y, int color) : CKoopa(x, y, color)
{
	this->SetState(WINGED_KOOPA_STATE_JUMP);
	this->vx = -WINGED_KOOPA_WALKING_SPEED;
	this->isOnPlatform = false;
}

void CWingedKoopa::OnCollisionWith(LPCOLLISIONEVENT e)
{
	if (!e->obj->IsBlocking()) return;
	if (e->ny != 0 && e->obj->IsBlocking())
	{
		vy = 0;
		if (e->ny < 0) this->isOnPlatform = true ;
	}
	else if (e->nx != 0)
	{
		vx = -vx;
	}

}

void CWingedKoopa::OnNoCollision(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;
	this->isOnPlatform = false;
}


int CWingedKoopa::GetAniId()
{
	if (this->state == WINGED_KOOPA_STATE_JUMP) {
		if (this->vx < 0) {
			return ID_ANI_WINGED_KOOPA_JUMP_RIGHT;
		}
		else {
			return ID_ANI_WINGED_KOOPA_JUMP_LEFT;
		}
	}
	else if (this->state == WINGED_KOOPA_STATE_NO_WINGS_WALKING) {
		if (this->vx < 0) {
			return ID_ANI_KOOPA_WALKING_LEFT + this->color;
		}
		else {
			return ID_ANI_KOOPA_WALKING_RIGHT + this->color;
		}
	}
	return 0;
}

void CWingedKoopa::Render() {
	if (this->is_in_shell) return;
	CAnimations* animations = CAnimations::GetInstance();
	animations->Get(this->GetAniId())->Render(x, y);
}






void CWingedKoopa::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{


    if (this->state == WINGED_KOOPA_STATE_NO_WINGS_WALKING) {
        CKoopa::Update(dt, coObjects);
        return;
    }
	vy += ay * dt;
	vx += ax * dt;


	CEnemy::Update(dt,coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
	if (this->isOnPlatform) {
		this->vy = -WINGED_KOOPA_JUMP_SPEED;
		DebugOut(L"JUMP\n");
	}

}




void CWingedKoopa::Hitted(int nx)
{
	CKoopa::Hitted(nx);
}

void CWingedKoopa::Pressed()
{
	if (this->state == WINGED_KOOPA_STATE_NO_WINGS_WALKING) {
		CKoopa::Pressed();
		return;
	}
	this->SetState(WINGED_KOOPA_STATE_NO_WINGS_WALKING);
}

bool CWingedKoopa::IsInStateDie()
{
    return this->state == WINGED_KOOPA_STATE_DIE;
}
