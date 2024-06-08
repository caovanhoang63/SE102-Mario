#include "FireBullet.h"


CFireBullet::CFireBullet(float x, float y, LPGAMEOBJECT target) : CGameObject(x,y) {

	this->target = target;
	FindDirection();
	vx = cos(direction)*FIRE_BULLET_SPEED;
	vy = sin(direction)*FIRE_BULLET_SPEED;
}


void CFireBullet::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	animations->Get(ID_ANI_FIRE_BULLET)->Render(x,y);

}

void CFireBullet::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - FIRE_BULLET_BBOX_WIDTH / 2;
	t = y - FIRE_BULLET_BBOX_HEIGHT / 2;
	r = l + FIRE_BULLET_BBOX_WIDTH;
	b = t + FIRE_BULLET_BBOX_HEIGHT;
}
void CFireBullet::FindDirection() {
    float targetX, targetY;
    target->GetPosition(targetX, targetY);

    float dx = targetX - x;
    float dy = targetY - y;
    int angleFire = 0;
    // Tính góc alpha giữa vector (dx, dy) và trục hoành Ox
    float angle  = atan2(dy, dx) * 180/M_PI;
    if (angle < 0 && angle >= -30)
    {
        angleFire = -30;
    }
    else if (angle < -30 && angle >= -90)
    {
        angleFire = -60;
    }
    else if (angle < -90 && angle >= -120)
    {
        angleFire = -120;
    }
    else if (angle < -120 && angle >= -180)
    {
        angleFire = -150;
    }
    else if   (angle >= 0 && angle <= 30) 
    {
        angleFire = 30;
    }
    else if (angle > 30 && angle <= 90) 
    {
        angleFire = 60;
    }
    else if (angle > 90 && angle <= 120) 
    {
        angleFire = 120;
    }
    else 
    {
        angleFire = 150;
    }

    direction = angleFire / (180 / M_PI);
    //// Xác định hướng dựa trên góc alpha
    //if (direction >= 0 && direction < DIRECTION_1) {
    //    // Hướng phải trên (30 độ)
    //    direction = DIRECTION_1;
    //}
    //else if (direction >= DIRECTION_1 && direction < DIRECTION_2) {
    //    // Hướng phải trên (60 độ)
    //    direction = DIRECTION_2;
    //}
    //else if (direction >= DIRECTION_2 && direction < M_PI / 2) {
    //    // Hướng trên (90 độ)
    //    direction = M_PI / 2;
    //}
    //else if (direction >= M_PI / 2 && direction < DIRECTION_4) {
    //    // Hướng trái trên (150 độ)
    //    direction = DIRECTION_4;
    //}
    //else if (direction >= DIRECTION_4 && direction < DIRECTION_5) {
    //    // Hướng trái (210 độ)
    //    direction = DIRECTION_5;
    //}
    //else if (direction >= DIRECTION_5 && direction < 3 * M_PI / 2) {
    //    // Hướng dưới (270 độ)
    //    direction = 3 * M_PI / 2;
    //}
    //else if (direction >= 3 * M_PI / 2 && direction < DIRECTION_7) {
    //    // Hướng trái dưới (330 độ)
    //    direction = DIRECTION_7;
    //}
    //else {
    //    // Hướng phải trên (30 độ)
    //    direction = DIRECTION_1;
    //}
}

void CFireBullet::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {
    this->x += dt * vx;
    this->y += dt * vy;
    CCollision::GetInstance()->Process(this, dt, coObjects);
}


