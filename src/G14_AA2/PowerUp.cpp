#include "PowerUp.h"



PowerUp::PowerUp()
{
	active = true;
	powerUpType = 0;
}


PowerUp::~PowerUp()
{
}

void PowerUp::createPowerUp(int posX, int posY)
{
	powerupRect = { posX, posY, 48, 48 };
	int result = rand() % 2;
	if (result == 1)
	{
		powerupTarget = { 48, 48, 48, 48 };
		powerUpType = 1;
	}
	else
	{
		powerupTarget = { 96, 48, 48, 48 };
		powerUpType = 2;
	}
}

void PowerUp::drawPowerUp()
{
	Renderer::Instance()->PushSprite(ITEMS_SPRITE, powerupTarget, powerupRect);
}
