#include "CColorBox.h"

#include "Sprite.h"
#include "Sprites.h"

#include "Textures.h"



void CColorBox::Render()
{
	/*CAnimations* animations = CAnimations::GetInstance();
	animations->Get(this->IdSprite)->Render(x, y);*/
	CSprites* s = CSprites::GetInstance();
	s->Get(this->IdSprite)->Draw(x, y);
	//RenderBoundingBox();
}

void CColorBox::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - Width / 2;
	t = y - Height / 2;
	r = l + Width;
	b = t + Height;
}

int CColorBox::IsDirectionColliable(float nx, float ny) {
	if (nx ==  0 && ny == - 1) {
		return 1;
	}
	else {
		return 0;
	}

}