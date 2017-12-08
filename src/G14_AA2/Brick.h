#pragma once
#include <SDL.h>
#include "Renderer.h"
class Brick
{
public:
	Brick(int posX, int posY);
	~Brick();


	SDL_Rect wallRect, wallTarget;

	int frameWidth, frameHeight;

	Vector2 imageSize = Renderer::Instance()->GetTextureSize(PATH_WALL);
};

