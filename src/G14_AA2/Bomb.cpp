#include "Bomb.h"



Bomb::Bomb(int posX, int posY)
{
	bombRect = { posX, posY, 48, 48 };
	bombTarget = { 0, 48, 48, 48 };
	Renderer::Instance()->PushSprite(ITEMS_SPRITE, bombTarget, bombRect);
}


Bomb::~Bomb()
{
}
