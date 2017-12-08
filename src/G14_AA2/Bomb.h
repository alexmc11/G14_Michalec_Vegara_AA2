#include <SDL.h>
#include "Renderer.h"
#pragma once
class Bomb
{
public:

	SDL_Rect bombRect, bombPosition;

	int frameWidth, frameHeight;

	Vector2 imageSize = Renderer::Instance()->GetTextureSize(PATH_ITEMS);

	Bomb();
	~Bomb();
};

