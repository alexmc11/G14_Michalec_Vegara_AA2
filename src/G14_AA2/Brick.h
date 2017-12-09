#pragma once
#include <SDL.h>
#include "Renderer.h"


class Brick
{
public:
	Brick();
	~Brick();
	void printBrick(int posX, int posY);

	void printDestructible(int posX, int posY);

	SDL_Rect wallRect, wallTarget, brickRect, brickTarget;

	int frameWidth, frameHeight;

	Vector2 imageSize = Renderer::Instance()->GetTextureSize(PATH_WALL);

};

