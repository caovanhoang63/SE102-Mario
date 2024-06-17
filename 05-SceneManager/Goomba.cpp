#include "Goomba.h"

CGoomba::CGoomba(float x, float y): CEnemy(x, y )
{
	this->ax = 0;
	this->ay = GOOMBA_GRAVITY;
	die_start = -1;
	SetState(GOOMBA_STATE_WALKING);
}

void CGoomba::Hitted(int nx)
{
	CEnemy::Hitted(nx);
	if (this->GetState() != GOOMBA_STATE_DIE)
	{
		this->SetState(GOOMBA_STATE_DIE);
	}
}

void CGoomba::Pressed()
{
	CEnemy::Pressed();
	if (this->GetState() != GOOMBA_STATE_DIE)
	{
		this->SetState(GOOMBA_STATE_DIE);
	}
}

bool CGoomba::IsInStateDie()
{
	return this->state == GOOMBA_STATE_DIE;
}



void CGoomba::GetBoundingBox(float &left, float &top, float &right, float &bottom)
{
	if (state == GOOMBA_STATE_DIE)
	{
		left = x - GOOMBA_BBOX_WIDTH/2;
		top = y - GOOMBA_BBOX_HEIGHT_DIE/2;
		right = left + GOOMBA_BBOX_WIDTH;
		bottom = top + GOOMBA_BBOX_HEIGHT_DIE;
	}
	else
	{ 
		left = x - GOOMBA_BBOX_WIDTH/2;
		top = y - GOOMBA_BBOX_HEIGHT/2;
		right = left + GOOMBA_BBOX_WIDTH;
		bottom = top + GOOMBA_BBOX_HEIGHT;
	}
}

void CGoomba::OnNoCollision(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;
};

void CGoomba::OnCollisionWith(LPCOLLISIONEVENT e)
{
	if (!e->obj->IsBlocking()) return; 
	if (dynamic_cast<CGoomba*>(e->obj)) return; 
	if (e->ny != 0 )
	{
		vy = 0;
	}
	else if (e->nx != 0)
	{
		vx = -vx;
	}
}

void CGoomba::Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects)
{
	vy += ay * dt;
	vx += ax * dt;

	if ( (state==GOOMBA_STATE_DIE) && (GetTickCount64() - die_start > GOOMBA_DIE_TIMEOUT) )
	{
		isDeleted = true;
		return;
	}

	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}


void CGoomba::Render()
{
	int aniId = ID_ANI_GOOMBA_WALKING;
	if (isPressed)
		aniId = ID_ANI_GOOMBA_PRESSED;
	else if (isHitted)
		aniId = ID_ANI_GOOMBA_HITTED;


	CAnimations::GetInstance()->Get(aniId)->Render(x,y);
	//RenderBoundingBox();
}


void CGoomba::SetState(int state)
{
	CGameObject::SetState(state);
	switch (state)
	{
		case GOOMBA_STATE_DIE:
			die_start = GetTickCount64();

			if (isPressed) {
				y += (GOOMBA_BBOX_HEIGHT - GOOMBA_BBOX_HEIGHT_DIE) / 2;
				vx = 0;
				vy = 0;
				ay = 0;
			}
			else  {
				vx = isHitted > 0 ? -GOOMBA_WALKING_SPEED : GOOMBA_WALKING_SPEED;
				vy = -0.3f;
			}
			break;
		case GOOMBA_STATE_WALKING: 
			vx = -GOOMBA_WALKING_SPEED;
			break;
	}
}
