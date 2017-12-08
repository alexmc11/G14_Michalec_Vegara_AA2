#include <SDL.h>
#include "Renderer.h"
#pragma once
class Bomb
{
public:

	Bomb(int posX, int posY);

	SDL_Rect bombRect, bombTarget;

	Vector2 imageSize = Renderer::Instance()->GetTextureSize(PATH_ITEMS);

	~Bomb();
};

