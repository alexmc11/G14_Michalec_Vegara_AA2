#include <SDL.h>
#include "Renderer.h"
#pragma once

class HUD
{
public:
	HUD();
	~HUD();

	SDL_Rect player1Vidas, player2Vidas, BG;
};

