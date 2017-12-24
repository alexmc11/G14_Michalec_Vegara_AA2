#pragma once
#include <SDL.h>
#include "Renderer.h"
#include "Bomb.h"
#include "Map.h"
#include <math.h>
#include <iostream>

enum playerTag { player1, player2 };
enum direction { UP, DOWN, LEFT, RIGHT, DEFAULT };

struct Position 
{
	int x;
	int y;
};

struct target
{
	int x;
	int y;
};

class Character
{
public:

	playerTag player;

	SDL_Rect playerRect, playerPosition, playerTarget;

	int points;
	int lives;
	int speed;

	direction lastkey;

	bool hasbomb;
	bool explode;
	bool colision;
	bool hasimmunity;

	int textWidth, textHeight, frameWidth, frameHeight;

	Vector2 image1Size = Renderer::Instance()->GetTextureSize(PATH_PLAYER1);
	Vector2 image2Size = Renderer::Instance()->GetTextureSize(PATH_PLAYER2);

	int frameTime = 0;

	Position position;

	target objective;

	SDL_Event event;

	Bomb *bomb;

	Character(playerTag Player);

	~Character();
	void movement();
};
