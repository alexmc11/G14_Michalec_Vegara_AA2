#pragma once
#include <SDL.h>
#include "Renderer.h"

enum brickType { destructible, nonDestructible };

class Brick
{
public:
	Brick();
	~Brick();

	int posicionX, posicionY;

	void printBrick(int posX, int posY);

	void printDestructible(int posX, int posY);

	SDL_Rect wallRect, wallTarget, brickRect, brickTarget;

	int frameWidth, frameHeight;

	brickType tipoLadrillo;

	std::vector<SDL_Rect> colisionesNoDestructible;

	std::vector<SDL_Rect> colisionesDestructible;

};

