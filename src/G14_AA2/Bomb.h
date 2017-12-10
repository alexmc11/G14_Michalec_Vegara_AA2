#include <SDL.h>
#include "Renderer.h"
#include <time.h>
#include <iostream>
#pragma once
class Bomb
{
public:

	Bomb(int posX, int posY);

	void bombExplode(int posX, int posY);

	void placeBomb();

	int posicionX, posicionY;

	SDL_Rect bombRect, explodeCenter, explodeUp1, explodeUp2, explodeLeft1, explodeLeft2, explodeRight1, explodeRight2, explodeDown1, explodeDown2;
	SDL_Rect bombTarget, centerTarget, up1Target, up2Target, left1Target, left2Taget, right1Target, right2Target, down1Target, down2Target;

	Vector2 imageSize = Renderer::Instance()->GetTextureSize(PATH_ITEMS);

	Vector2 explodeImageSize = Renderer::Instance()->GetTextureSize(PATH_EXPLOSION);

	~Bomb();
};

