#include "Brick.h"



Brick::Brick()
{
}


Brick::~Brick()
{
}

void Brick::printBrick(int posX, int posY)
{
	wallRect = { posX, posY, 48, 48 };
	wallTarget = { 0, 0, 48, 48 };
	Renderer::Instance()->PushSprite(ITEMS_SPRITE, wallTarget, wallRect);
	
}

void Brick::printDestructible(int posX, int posY)
{
	brickRect = { posX, posY, 48, 48 };
	brickTarget = { 48, 0, 48, 48 };
	Renderer::Instance()->PushSprite(ITEMS_SPRITE, brickTarget, brickRect);
}
