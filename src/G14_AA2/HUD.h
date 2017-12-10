#include <SDL.h>
#include "Renderer.h"
#pragma once

class HUD
{
public:
	HUD();
	~HUD();

	void DrawHud();

	SDL_Rect vidas1, vidas2, vidas1Num, vidas2Num;

	Vector2 medidaVidas = Renderer::Instance()->GetTextureSize(TEXT_VIDAS);
	Vector2 medidaVidas2 = Renderer::Instance()->GetTextureSize(TEXT_VIDAS2);
};

