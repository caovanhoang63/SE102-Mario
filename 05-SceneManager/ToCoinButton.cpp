#include "ToCoinButton.h"
#include "PlayScene.h"


void CToCoinButton::GenCoin()
{
	if (isPressed) return;
	CPlayScene* scene = dynamic_cast<CPlayScene*>(CGame::GetInstance()->GetCurrentScene());
	scene->BrickToCoin();
	isPressed = true;
	this->y += 4;
}
