#include <SDL.h>
#include "Renderer.h"
#pragma once

class HUD
{
public:
	HUD();
	~HUD();

	SDL_Rect player1Vidas, player2Vidas, puntos1BG, puntos2BG, vidas1BG, vidas2BG, tiempoBG;
};

