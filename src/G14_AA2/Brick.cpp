#include "Brick.h"



Brick::Brick(int posX, int posY)
{
	wallRect = { posX, posY, 48, 48 };
	wallTarget = { 0, 0, 48, 48 };
	Renderer::Instance()->PushSprite(ITEMS_SPRITE, wallTarget, wallRect);
	Renderer::Instance()->Render();
}


Brick::~Brick()
{
}
