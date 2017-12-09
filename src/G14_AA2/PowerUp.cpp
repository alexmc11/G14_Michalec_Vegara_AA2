#include "PowerUp.h"



PowerUp::PowerUp()
{
}


PowerUp::~PowerUp()
{
}

void PowerUp::createPowerUp(int posX, int posY)
{
	powerupRect = { posX, posY, 48, 48 };
	int result = rand() % 1;
	if (result == 1)
	{
		powerupTarget = { 48, 48, 48, 48 };
	}
	else
	{
		powerupTarget = { 96, 48, 48, 48 };
	}
	Renderer::Instance()->PushSprite(ITEMS_SPRITE, powerupTarget, powerupRect);
}
