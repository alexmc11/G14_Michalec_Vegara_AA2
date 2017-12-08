#pragma once
#include <SDL.h>
#include "Renderer.h"
class Brick
{
public:
	Brick(int posX, int posY);
	~Brick();


	SDL_Rect destructibleBrick, nondestructibleBrick;
};

