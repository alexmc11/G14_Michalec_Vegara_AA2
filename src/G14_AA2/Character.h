#pragma once
#include <SDL.h>
enum playerTag {player1, player2};

struct Position {
	float x;
	float y;
};
class Character
{
public:
	playerTag player;
	SDL_Rect playerRect;
	Position playerPosition;
	SDL_Event event;
	Character(playerTag player);
	~Character();
	void movement(playerTag player);
};

