#pragma once
#include "GameObject.h"


#define ID_ANI_TO_COIN_BUTTON 270000
#define ID_ANI_TO_COIN_BUTTON_PRESSED 270001
#define BUTTON_WIDTH 16
#define BUTTON_HEIGHT 16
#define BUTTON_HEIGHT_PRESSED 6

class CToCoinButton :
    public CGameObject
{
protected:
	bool isPressed = false;
public:
    CToCoinButton(float x, float y ) : CGameObject (x,y){
		isPressed = false;
	}
	void Render() {
		CAnimations* animations = CAnimations::GetInstance();
		if (isPressed)
			animations->Get(ID_ANI_TO_COIN_BUTTON_PRESSED)->Render(x, y);
		else
			animations->Get(ID_ANI_TO_COIN_BUTTON)->Render(x, y);
	}
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {}
	virtual void OnCollisionWith(LPCOLLISIONEVENT e) {};
	virtual void GenCoin();
	void GetBoundingBox(float& l, float& t, float& r, float& b) {
		if (!isPressed) {
			l = x - BUTTON_WIDTH / 2;
			t = y - BUTTON_HEIGHT / 2;
			r = l + BUTTON_WIDTH;
			b = t + BUTTON_HEIGHT;
		}
		else {
			l = x - BUTTON_WIDTH / 2;
			t = y - BUTTON_HEIGHT_PRESSED / 2;
			r = l + BUTTON_WIDTH;
			b = t + BUTTON_HEIGHT_PRESSED;
		}
		
	}
	virtual int IsCollidable() { return 1; };
};

