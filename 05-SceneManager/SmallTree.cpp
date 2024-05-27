#include "SmallTree.h"

#include "Sprite.h"
#include "Sprites.h"

#include "Textures.h"

void CSmallTree::Render()
{
	/*CAnimations* animations = CAnimations::GetInstance();
	animations->Get(this->IdSprite)->Render(x, y);*/
	CSprites* s = CSprites::GetInstance();
	s->Get(this->IdSprite)->Draw(x, y);
	//RenderBoundingBox();
}

void CSmallTree::GetBoundingBox(float& l, float& t, float& r, float& b)
{

}