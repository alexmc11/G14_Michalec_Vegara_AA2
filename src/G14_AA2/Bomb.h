#include <SDL.h>
#include "Renderer.h"
#pragma once
class Bomb
{
public:

	SDL_Rect bombRect, bombPosition;

	int textWidth, textHeight, frameWidth, frameHeight;

	//SDL_QueryTexture(PATH_ITEMS, NULL, NULL, &textWidth, &textHeight);

	Vector2 imageSize = Renderer::Instance()->GetTextureSize(PATH_ITEMS);

	/*frameWidth = imageSize.x;

	frameHeight = textHeight / 2;

	bombPosition.x = bombPosition.y = 0;

	playerRect.x = playerRect.y = 0;

	playerPosition.h = playerRect.h = frameHeight;

	playerPosition.w = playerRect.w = frameWidth;*/

	int frameTime = 0;

	Bomb();
	~Bomb();
};

