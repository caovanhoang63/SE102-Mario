#pragma once
#include "GameObject.h"
#include "LongBackground.h"

class COneWayLongBlock :  public CLongBackground
{
public:
	COneWayLongBlock(float x, float y,
		float cell_width, float cell_height, int length,
		int sprite_id_begin, int sprite_id_middle, int sprite_id_end) :CLongBackground(x, y, cell_height, cell_width, length, sprite_id_begin, sprite_id_middle, sprite_id_end)
	{
		this->length = length;
		this->cellWidth = cell_width;
		this->cellHeight = cell_height;
		this->spriteIdBegin = sprite_id_begin;
		this->spriteIdMiddle = sprite_id_middle;
		this->spriteIdEnd = sprite_id_end;
	}
	int IsBlocking() { return 1; }
	int IsDirectionColliable(float nx, float ny)
	{
		if (nx == 0 && ny == -1)
			return 1;
		else
			return 0;
	}
};

