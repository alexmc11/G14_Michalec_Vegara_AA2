#pragma once
#include <SDL.h>
#include "Renderer.h"
class PowerUp
{
public:
	SDL_Rect powerupRect, powerupTarget;
	PowerUp();
	~PowerUp();
	void createPowerUp(int posX, int posY);
};

