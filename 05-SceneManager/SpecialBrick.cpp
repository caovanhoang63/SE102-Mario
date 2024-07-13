#include "SpecialBrick.h"
#include "KoopaShell.h"
#include "PlayScene.h"
#include "ToCoinButton.h"

void CSpecialBrick::Hitted()
{
	GenButton();
}

void CSpecialBrick::GenButton()
{
	CPlayScene* scene = dynamic_cast<CPlayScene*>(CGame::GetInstance()->GetCurrentScene());
	scene->AddNewObjectToTail(new CToCoinButton(x, y - 16));
	isCollision = true;

}

void CSpecialBrick::OnCollisionWith(LPCOLLISIONEVENT e)
{
	if (dynamic_cast<CKoopaShell*>(e->obj)) {
		CKoopaShell* shell = dynamic_cast<CKoopaShell*>(e->obj);
		if (shell->GetState() == KOOPA_SHELL_STATE_MOVING) {
			float vx, vy;
			shell->GetSpeed(vx, vy);
			shell->SetSpeed(-vx, vy);
			CPlayScene* scene = dynamic_cast<CPlayScene*>(CGame::GetInstance()->GetCurrentScene());
			scene->AddNewObjectToTail(new CToCoinButton(x, y + 12));
			isCollision = true;
		}
	}
}

void CSpecialBrick::Render()
{
	if (!isCollision) {
		CBrick::Render();
	}
	else {
		CAnimations* animations = CAnimations::GetInstance();
		animations->Get(ID_ANI_EMPTY_BRICK)->Render(x, y);
	}

	RenderBoundingBox();
}