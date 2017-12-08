#pragma once
#include <SDL.h>
#include "Renderer.h"
#define FPS 60
enum playerTag {player1, player2};

struct Position {
	float x;
	float y;
};
class Character
{
public:
	playerTag player;
	SDL_Rect player1Rect, player2Rect, player1Position, player2Position;

	int textWidth, textHeight, frameWidth, frameHeight;

	int text2Width, text2Height, frame2Width, frame2Height;

	Vector2 image1Size = Renderer::Instance()->GetTextureSize(PATH_PLAYER1);

	Vector2 image2Size = Renderer::Instance()->GetTextureSize(PATH_PLAYER2);

	int frameTime = 0;

	int vidas = 3;

	int puntos = 0;

	Position posicion1;
	Position posicion2;
	SDL_Event event;
	Character();
	~Character();
	void movement();
};

