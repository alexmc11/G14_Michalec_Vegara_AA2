#pragma once
#include <SDL.h>
#include "Renderer.h"
class PowerUp
{
public:
	SDL_Rect powerupRect, powerupTarget;
	PowerUp();
	~PowerUp();
	int powerUpType;
	bool active;
	void drawPowerUp();
	void createPowerUp(int posX, int posY);
};

