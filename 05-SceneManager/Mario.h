#pragma once
#include "GameObject.h"

#include "Animation.h"
#include "Animations.h"
#include "KoopaShell.h"

#include "debug.h"

#define MARIO_WALKING_SPEED		0.1f
#define MARIO_RUNNING_SPEED		0.3f

#define MARIO_ACCEL_WALK_X	0.0005f
#define MARIO_ACCEL_RUN_X	0.0007f

#define MARIO_JUMP_SPEED_Y		0.5f
#define MARIO_JUMP_RUN_SPEED_Y	0.6f

#define MARIO_GRAVITY			0.002f

#define MARIO_JUMP_DEFLECT_SPEED  0.4f

#define MARIO_STATE_DIE				-10
#define MARIO_STATE_IDLE			0
#define MARIO_STATE_WALKING_RIGHT	100
#define MARIO_STATE_WALKING_LEFT	200

#define MARIO_STATE_JUMP			300
#define MARIO_STATE_RELEASE_JUMP    301

#define MARIO_STATE_RUNNING_RIGHT	400
#define MARIO_STATE_RUNNING_LEFT	500

#define MARIO_STATE_SIT				600
#define MARIO_STATE_SIT_RELEASE		601

#define MARIO_STATE_HOLD_SHELL_LEFT	700
#define MARIO_STATE_HOLD_SHELL_RIGHT	701

#define MARIO_STATE_SPIN	800



#define MARIO_SHELL_X_OFF_SET	12
#define MARIO_RACOON_SHELL_X_OFF_SET	16
#define MARIO_SHELL_Y_OFF_SET	1

#pragma region ANIMATION_ID

#define ID_ANI_MARIO_IDLE_RIGHT 400
#define ID_ANI_MARIO_IDLE_LEFT 401

#define ID_ANI_MARIO_WALKING_RIGHT 500
#define ID_ANI_MARIO_WALKING_LEFT 501

#define ID_ANI_MARIO_RUNNING_RIGHT 600
#define ID_ANI_MARIO_RUNNING_LEFT 601

#define ID_ANI_MARIO_JUMP_WALK_RIGHT 700
#define ID_ANI_MARIO_JUMP_WALK_LEFT 701

#define ID_ANI_MARIO_JUMP_RUN_RIGHT 800
#define ID_ANI_MARIO_JUMP_RUN_LEFT 801


#define ID_ANI_MARIO_SIT_RIGHT 900
#define ID_ANI_MARIO_SIT_LEFT 901

#define ID_ANI_MARIO_BRACE_RIGHT 1000
#define ID_ANI_MARIO_BRACE_LEFT 1001


#define ID_ANI_MARIO_HOLDING_SHELL_RUN_LEFT	1010
#define ID_ANI_MARIO_HOLDING_SHELL_RUN_RIGHT	1011

#define ID_ANI_MARIO_HOLDING_SHELL_JUMP_LEFT	1020
#define ID_ANI_MARIO_HOLDING_SHELL_JUMP_RIGHT	1021

#define ID_ANI_MARIO_LEFT_KICK 1030
#define ID_ANI_MARIO_RIGHT_KICK 1031

#define ID_ANI_MARIO_HOLDING_SHELL_IDLE_LEFT 1040
#define ID_ANI_MARIO_HOLDING_SHELL_IDLE_RIGHT 1041


#define ID_ANI_MARIO_DIE 999

// SMALL MARIO
#define ID_ANI_MARIO_SMALL_IDLE_RIGHT 1100
#define ID_ANI_MARIO_SMALL_IDLE_LEFT 1102

#define ID_ANI_MARIO_SMALL_WALKING_RIGHT 1200
#define ID_ANI_MARIO_SMALL_WALKING_LEFT 1201

#define ID_ANI_MARIO_SMALL_RUNNING_RIGHT 1300
#define ID_ANI_MARIO_SMALL_RUNNING_LEFT 1301

#define ID_ANI_MARIO_SMALL_BRACE_RIGHT 1400
#define ID_ANI_MARIO_SMALL_BRACE_LEFT 1401

#define ID_ANI_MARIO_SMALL_JUMP_WALK_RIGHT 1500
#define ID_ANI_MARIO_SMALL_JUMP_WALK_LEFT 1501

#define ID_ANI_MARIO_SMALL_JUMP_RUN_RIGHT 1600
#define ID_ANI_MARIO_SMALL_JUMP_RUN_LEFT 1601

#define ID_ANI_MARIO_SMALL_HOLDING_SHELL_RUN_LEFT	1700
#define ID_ANI_MARIO_SMALL_HOLDING_SHELL_RUN_RIGHT	1701

#define ID_ANI_MARIO_SMALL_HOLDING_SHELL_JUMP_LEFT	1800
#define ID_ANI_MARIO_SMALL_HOLDING_SHELL_JUMP_RIGHT	1801

#define ID_ANI_MARIO_SMALL_LEFT_KICK 1900
#define ID_ANI_MARIO_SMALL_RIGHT_KICK 1901

#define ID_ANI_MARIO_SMALL_HOLDING_SHELL_IDLE_LEFT 1910
#define ID_ANI_MARIO_SMALL_HOLDING_SHELL_IDLE_RIGHT 1911

// RACOON MARIO

#define ID_ANI_MARIO_RACOON_IDLE_RIGHT 2400
#define ID_ANI_MARIO_RACOON_IDLE_LEFT 2401

#define ID_ANI_MARIO_RACOON_WALKING_RIGHT 2500
#define ID_ANI_MARIO_RACOON_WALKING_LEFT 2501

#define ID_ANI_MARIO_RACOON_RUNNING_RIGHT 2600
#define ID_ANI_MARIO_RACOON_RUNNING_LEFT 2601

#define ID_ANI_MARIO_RACOON_RUNNING_MAX_SPEED_RIGHT 2610
#define ID_ANI_MARIO_RACOON_RUNNING_MAX_SPEED_LEFT 2611

#define ID_ANI_MARIO_RACOON_JUMP_WALK_RIGHT 2700
#define ID_ANI_MARIO_RACOON_JUMP_WALK_LEFT 2701

#define ID_ANI_MARIO_RACOON_JUMP_RUN_RIGHT 2800
#define ID_ANI_MARIO_RACOON_JUMP_RUN_LEFT 2801


#define ID_ANI_MARIO_RACOON_SIT_RIGHT 2900
#define ID_ANI_MARIO_RACOON_SIT_LEFT 2901

#define ID_ANI_MARIO_RACOON_BRACE_RIGHT 2000
#define ID_ANI_MARIO_RACOON_BRACE_LEFT 2001


#define ID_ANI_MARIO_RACOON_HOLDING_SHELL_RUN_LEFT	2010
#define ID_ANI_MARIO_RACOON_HOLDING_SHELL_RUN_RIGHT	2011

#define ID_ANI_MARIO_RACOON_HOLDING_SHELL_JUMP_LEFT	2020
#define ID_ANI_MARIO_RACOON_HOLDING_SHELL_JUMP_RIGHT	2021

#define ID_ANI_MARIO_RACOON_LEFT_KICK 2030
#define ID_ANI_MARIO_RACOON_RIGHT_KICK 2031

#define ID_ANI_MARIO_RACOON_HOLDING_SHELL_IDLE_LEFT 2040
#define ID_ANI_MARIO_RACOON_HOLDING_SHELL_IDLE_RIGHT 2041

#define ID_ANI_MARIO_RACOON_SPIN_LEFT 2100
#define ID_ANI_MARIO_RACOON_SPIN_RIGHT 2101


#pragma endregion

#define GROUND_Y 160.0f




#define	MARIO_LEVEL_SMALL	1
#define	MARIO_LEVEL_BIG		2
#define MARIO_LEVEL_RACOON_FORM 3

#define MARIO_BIG_BBOX_WIDTH  14
#define MARIO_BIG_BBOX_HEIGHT 24
#define MARIO_BIG_SITTING_BBOX_WIDTH  14
#define MARIO_BIG_SITTING_BBOX_HEIGHT 16

#define MARIO_RACOON_BBOX_WIDTH  16
#define MARIO_RACOON_BBOX_HEIGHT 26
#define MARIO_RACOON_SITTING_BBOX_WIDTH  14
#define MARIO_RACOON_SITTING_BBOX_HEIGHT 16


#define MARIO_SIT_HEIGHT_ADJUST ((MARIO_BIG_BBOX_HEIGHT-MARIO_BIG_SITTING_BBOX_HEIGHT)/2)

#define MARIO_SMALL_BBOX_WIDTH  13
#define MARIO_SMALL_BBOX_HEIGHT 12


#define MARIO_UNTOUCHABLE_TIME 2500
#define MARIO_KICK_TIME 300
#define MARIO_SPIN_TIME 400

class CMario : public CGameObject
{
	BOOLEAN isSitting,isSpin,canFly;
	float maxVx;
	float ax;				// acceleration on x 
	float ay;				// acceleration on y 

	int level; 
	int untouchable; 
	ULONGLONG untouchable_start,kick_start,spin_start;
	BOOLEAN isOnPlatform, isHoldingShell, inKickAni;
	int coin; 
	CKoopaShell* shell;
	void OnCollisionWithGoomba(LPCOLLISIONEVENT e);
	void OnCollisionWithCoin(LPCOLLISIONEVENT e);
	void OnCollosionWithGiftBox(LPCOLLISIONEVENT e);
	void OnCollisionWithPortal(LPCOLLISIONEVENT e);
	void OnCollisionWithMushroom(LPCOLLISIONEVENT e);
	void OnCollisionWithKoopa(LPCOLLISIONEVENT e);
	void OnCollisionWithKoopaShell(LPCOLLISIONEVENT e);
	void OnCollisionWithFireBullet(LPCOLLISIONEVENT e);
	void OnCollisionWithWingedGoomba(LPCOLLISIONEVENT e);
	void OnCollisionWithLeaf(LPCOLLISIONEVENT e);
	void OnCollisionWithEnemy(LPCOLLISIONEVENT e);
	int GetAniIdRacoon();
	int GetAniIdBig();
	int GetAniIdSmall();

public:
	CMario(float x, float y) : CGameObject(x, y)
	{
		isSitting = false;
		maxVx = 0.0f;
		ax = 0.0f;
		ay = MARIO_GRAVITY; 
		this->shell = NULL;
		canFly = false;
		isHoldingShell = false;
		isSpin = false;
		spin_start = -1;
		level = MARIO_LEVEL_BIG;
		untouchable = 0;
		untouchable_start = -1;
		isOnPlatform = false;
		kick_start = 0;
		inKickAni = false;
		coin = 0;
	}
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void Render();
	void SetState(int state);
	int IsCollidable()
	{ 
		return (state != MARIO_STATE_DIE); 
	}
	int GetLevel() { return this->level; }
	int IsBlocking() { return (state != MARIO_STATE_DIE && untouchable==0); }
	bool IsHoldingShell() { return isHoldingShell; }
	bool CanKillEnemy(LPCOLLISIONEVENT e) { return (e->ny < 0 || isSpin); }
	void UpdateShellPosition();
	void OnNoCollision(DWORD dt);
	void OnCollisionWith(LPCOLLISIONEVENT e);
	void SetLevel(int l);
	void StartSpin() { isSpin = true; spin_start = GetTickCount64(); }
	void StartUntouchable() { untouchable = 1; untouchable_start = GetTickCount64(); }
	void StartKickAni() { inKickAni = true; kick_start = GetTickCount64(); }
	void HoldShell(CKoopaShell* shell);
	void ReleaseShell();
	void GetBoundingBox(float& left, float& top, float& right, float& bottom);
};