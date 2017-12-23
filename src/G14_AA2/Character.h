#pragma once
#include <SDL.h>
#include "Renderer.h"
#include "Bomb.h"
#include "Map.h"
#include <math.h>
#include <iostream>

enum playerTag { player1, player2 };
enum direccion { UP, DOWN, LEFT, RIGHT, DEFAULT };

struct Position {
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
	Map mapa;
	playerTag player;
	SDL_Rect playerRect, playerPosition;
	SDL_Rect playerTarget;
	int points;
	int vidas;
	void collisionMovement();
	direccion lastkey;
	bool hasbomb;
	bool explode;
	bool colision;
	bool hasimmunity = false;
	float timer;
	const Uint8* key = SDL_GetKeyboardState(NULL);

	int textWidth, textHeight, frameWidth, frameHeight;

	/*bool colisiones(SDL_Rect* A, SDL_Rect* B);

	bool iteradorcolisiones();*/

	//int text2Width, text2Height, frame2Width, frame2Height;

	Vector2 image1Size = Renderer::Instance()->GetTextureSize(PATH_PLAYER1);

	Vector2 image2Size = Renderer::Instance()->GetTextureSize(PATH_PLAYER2);

	int frameTime = 0;

	Position posicion;

	target objetivo;

	SDL_Event event;
	SDL_Event event2;

	Bomb *bomba;

	Character(playerTag jugador);
	~Character();
	void movement();
	void movement2();
};
