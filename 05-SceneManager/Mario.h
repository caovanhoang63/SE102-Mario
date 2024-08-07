#pragma once
#include "GameObject.h"

#include "Animation.h"
#include "Animations.h"
#include "KoopaShell.h"

#include "debug.h"

#define MARIO_WALKING_SPEED		0.1f
#define MARIO_RUNNING_SPEED		0.2f
#define MARIO_DRAG_FORCE		0.0018f
#define MARIO_ACCEL_WALK_X	0.0003f
#define MARIO_ACCEL_RUN_X	0.0005f
#define MARIO_WALKING_FRICTION_X	0.0001f
#define MARIO_RUNNING_FRICTION_X	0.0002f
#define MARIO_MAX_FALLING_SPEED	0.4f

#define MARIO_MAX_MANA		900
#define MARIO_MANA_STEP		150

#define MARIO_JUMP_SPEED_Y		0.5f
#define MARIO_JUMP_RUN_SPEED_Y	0.6f
#define MARIO_JUMP_DRAG_SPEED_Y	0.05f
#define MARIO_FLY_SPEED_Y	0.3f

#define MARIO_GRAVITY			0.0018f

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
#define MARIO_STATE_FLY	900
#define MARIO_STATE_FALL	1000


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

#define ID_ANI_MARIO_RACOON_DROP_LEFT 2110
#define ID_ANI_MARIO_RACOON_DROP_RIGHT 2111

#define ID_ANI_MARIO_RACOON_WAGGING_TAIL_LEFT 2120
#define ID_ANI_MARIO_RACOON_WAGGING_TAIL_RIGHT 2121

#define ID_ANI_MARIO_RACOON_FLY_WAGGING_TAIL_LEFT 2130
#define ID_ANI_MARIO_RACOON_FLY_WAGGING_TAIL_RIGHT 2131

#define ID_ANI_MARIO_RACOON_FLY_FALLING_LEFT 2140
#define ID_ANI_MARIO_RACOON_FLY_FALLING_RIGHT 2141

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
#define MARIO_JUMP_DRAG_FORCE_TIME 100
#define MARIO_FLY_DRAG_FORCE_TIME 500
#define MARIO_DECREASE_MANA_TIME 600
#define MARIO_FLY_TIME 10000
#define MARIO_WAGGING_TIME 100
#define	MARIO_JUMP_MAX_SCORE 8

class CMario : public CGameObject
{
	BOOLEAN isSitting,
		isSpin,
		canFly,
		isFlying,
		isInInertia, 
		isWagging, 
		isFallingAfterFly,
		isCameraLock;
	float maxVx;
	float ax;				// acceleration on x 
	float ay;				// acceleration on y 
	int mana_display;
	int mana;
	int level; 
	int untouchable; 
	int score;
	int jump_count ;
	ULONGLONG untouchable_start,
		kick_start,spin_start,
		fly_drag_force_start,
		jump_drag_force_start,
		flying_start,
		wagging_tail_start;
	BOOLEAN isOnPlatform, isHoldingShell, inKickAni;
	int coin; 
	int fly_count;
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
	void OnCollisionWithFlower(LPCOLLISIONEVENT e);
	void OnCollisionWithSpawner(LPCOLLISIONEVENT e);
	void OnCollisionWithButton(LPCOLLISIONEVENT e);
	void OnCollisionWithBrick(LPCOLLISIONEVENT e);
	void OnCollisionWithFlowerNoFire(LPCOLLISIONEVENT e);
	void OnCollisonWithEndPoint(LPCOLLISIONEVENT e);
	int GetAniIdRacoon();
	int GetAniIdBig();
	int GetAniIdSmall();

public:
	CMario(float x, float y) : CGameObject(x, y)
	{
		fly_drag_force_start = -1;
		wagging_tail_start = -1;
		jump_drag_force_start = 1;
		spin_start = -1;
		untouchable_start = -1;
		flying_start = -1;
		kick_start = -1;
		jump_count = 0;

		isInInertia = false;
		isFlying = false;
		isSitting = false;
		canFly = false;
		isHoldingShell = false;
		isSpin = false;
		isOnPlatform = false;
		inKickAni = false;
		isWagging = false;
		isFallingAfterFly = false;
		isCameraLock = false ;

		mana_display = 0;
		mana = 0;
		fly_count = 0;
		maxVx = 0.0f;
		ax = 0.0f;
		ay = MARIO_GRAVITY; 
		this->shell = NULL;
		level = MARIO_LEVEL_BIG;
		untouchable = 0;
		coin = 0;
		score = 0;
	}

	void IncreaseMana(int  value) {
		mana += value;
		if (mana > MARIO_MAX_MANA) {
			mana = MARIO_MAX_MANA;
		}
		mana_display = mana / MARIO_MANA_STEP;
	}

	void DecreaseMana(int value) {
		mana -= value;
		if (mana < 0) {
			mana = 0;
		}
		mana_display = mana / MARIO_MANA_STEP;
	}
	void IncScore(int value) {score += value;}

	void IncScoreWhenStomp();
	bool IsCameraLock() { return isCameraLock; }
	void SetCameraLock(bool value) { isCameraLock = value; }
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void Render();
	void SetState(int state);
	int IsCollidable()
	{ 
		return (state != MARIO_STATE_DIE); 
	}
	void StartFly();
	int GetLevel() { return this->level; }
	void StartDragForce() {
		isWagging = true;
		this->wagging_tail_start = GetTickCount64();
		this->jump_drag_force_start = GetTickCount64();
		this->vy = MARIO_JUMP_DRAG_SPEED_Y;
		this->ay = 0;
	}
	bool GetIsFlying() { return isFlying; }
	bool GetIsFallingAfterFly() { return isFallingAfterFly; }
	void Hitted();
	bool IsOnPlatform() { return isOnPlatform; }
	int IsBlocking() { return (state != MARIO_STATE_DIE && untouchable==0); }
	bool IsFlying() { return isFlying; }
	bool IsHoldingShell() { return isHoldingShell; }
	bool CanKillEnemy(LPCOLLISIONEVENT e) { return (e->ny < 0 || (isSpin && e->nx != 0 )); }
	bool GetCanFly() { return canFly; }
	void PerformFly();
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