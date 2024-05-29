#include "Flower.h"
#include "Game.h"

CFlower::CFlower(float x, float y, int  width, int height, int color, CMario* Mario) : CGameObject (x,y) {
	this->initY = y;
	this->width = width;
	this->height = height;
	this->color = color;
	this->SetState(FLOWER_STATE_HIDDEN);
	this->direction = FLOWER_DIRECTION_TOP;
	this->Mario = Mario;
	this->attack_start = -1;
	this->rest_start = -1;
}

void CFlower::Render() { 
	CAnimations* animations = CAnimations::GetInstance();
	int ani = ANI_BASE_KEY;
	switch (this->GetState())
	{
	case FLOWER_STATE_HIDDEN: {
		return;
	}
	case FLOWER_STATE_UP: {
		ani +=  1 ;
		break;
	}
	case FLOWER_STATE_DOWN: {
		ani += 1 ;
		break;
	}
	case FLOWER_STATE_STOP: {
		break;
	}
	default:
		break;
	}
	animations->Get(ani + this->color + this->direction)->Render(x, y);
}


void CFlower::Observe() {
	
	float mx, my;
	this->Mario->GetPosition(mx, my);

	//float d = sqrt((mx - x) * (mx - x) + (my - y) * (my - y));
	float d = abs(mx - x);
	if (d <= 150  ){

		if (this->state == FLOWER_STATE_HIDDEN && !isRest) {
			this->SetState(FLOWER_STATE_UP);
		}
	}
	if (x > mx) {
		if (y > my) {
			this->direction = FLOWER_DIRECTION_TOP_LEFT;
		}
		else {
			this->direction = FLOWER_DIRECTION_BOTTOM_LEFT;
		}
	}
	else {
		if (y > my) {
			this->direction = FLOWER_DIRECTION_TOP_RIGHT;
		}
		else {
			this->direction = FLOWER_DIRECTION_BOTTOM_RIGHT;
		}
	}
}


void CFlower::Attack(vector<LPGAMEOBJECT>* coObjects) {

	float mx, my;
	this->Mario->GetPosition(mx, my);
	CFireBullet* bullet = new CFireBullet(x, y-10, Mario);
	CPlayScene* a = (CPlayScene*)CGame::GetInstance()->GetCurrentScene();
	a->AddNewObjectToTail(bullet);
	this->SetState(FLOWER_STATE_DOWN);
}
const float MIN_MOVE_DISTANCE = 0.1f; // Khoảng cách di chuyển tối thiểu trong mỗi khung hình
void CFlower::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {
	Observe();
	if ( this->state == FLOWER_STATE_STOP && GetTickCount64() - attack_start > ATTACK_TIME)
	{
		attack_start = 0;
		Attack(coObjects);
	}
	else if (this->state == FLOWER_STATE_HIDDEN && GetTickCount64() - rest_start > REST_TIME)
	{
		rest_start = 0;
		isRest = false;

	}
	else if (this->state == FLOWER_STATE_UP) {
		float distance = - this->height -this->initY + this->y-1; // Khoảng cách cần di chuyển
		float speed = distance / FLOWER_MOVING_TIME; // Tốc độ di chuyển
		this->y += speed* dt; // Cập nhật vị trí y theo tốc độ và thời gian dt
		if (this->y <= this->initY - this->height ) {
			this->y = this->initY - this->height;
			this->SetState(FLOWER_STATE_STOP);
			this->StartAttack();
		}
	}
	else if (this->state == FLOWER_STATE_DOWN) {
		float distance = this->initY - this->y +1  ; // Khoảng cách cần di chuyển
		float speed = distance / FLOWER_MOVING_TIME; // Tốc độ di chuyển (dương)
		float move_distance = max(1, speed * dt); // Đảm bảo di chuyển ít nhất MIN_MOVE_DISTANCE
		this->y += move_distance; // Cập nhật vị trí y tăng dần
		if (this->y > this->initY) { // Khi đạt đến vị trí ban đầu
			this->SetState(FLOWER_STATE_HIDDEN);
			StartRestTime();
		}
	}
	CGameObject::Update(dt,coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}

void CFlower::SetState(int state) {
	CGameObject::SetState(state);
}


void CFlower::GetBoundingBox(float& l, float& t, float& r, float& b) {
	l = x - this->width / 2;
	t = y - this->height / 2;
	r = l + this->width;
	b = t + this->height;
}