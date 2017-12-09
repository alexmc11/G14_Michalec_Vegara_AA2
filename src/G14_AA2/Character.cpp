#include "Character.h"


Character::Character(playerTag jugador)
{
	points = 0;
	vidas = 3;
	hasbomb = false;
	SDL_Event event;
	if (jugador == player1)
	{
		posicion.x = 48;
		posicion.y = 128;
		objetivo.x = 48;
		objetivo.y = 96;
		playerRect = { posicion.x, posicion.y, 48, 48 };
		playerTarget = { objetivo.x, objetivo.y, 48, 48 };
	}
	else
	{
		posicion.x = 624;
		posicion.y = 608;
		objetivo.x = 0;
		objetivo.y = 0;
		playerRect = { posicion.x, posicion.y, 48, 48 };
		playerTarget = { objetivo.x, objetivo.y, 48, 48 };		
	}
	player = jugador;
}

Character::~Character()
{
}

void Character::movement()
{
	if (SDL_PollEvent(&event))
	{
		if (event.type == SDL_KEYDOWN)
		{
			if (player == player1)
			{
				if (event.key.keysym.sym == SDLK_w && posicion.y > 128)
				{
					posicion.y -= 2;
					objetivo.y = 0;
					//objetivo.x = 0;
					frameTime++;
					if (FPS / frameTime <= 9)
					{
						frameTime = 0;
						objetivo.x += 48;
						if (objetivo.x >= 144)
						{
							objetivo.x = 0;
						}
					}
				}
				if (event.key.keysym.sym == SDLK_a && posicion.x > 48)
				{
					posicion.x -= 2;
					//objetivo.x = 0;
					objetivo.y = 48;
					frameTime++;
					if (FPS / frameTime <= 9)
					{
						frameTime = 0;
						objetivo.x += 48;
						if (objetivo.x >= 144)
						{
							objetivo.x = 0;
						}
					}
				}
				if (event.key.keysym.sym == SDLK_s && posicion.y < 608)
				{
					posicion.y += 2;
					//objetivo.x = 0;
					objetivo.y = 96;
					frameTime++;
					std::cout << frameTime;
					if (FPS / frameTime <= 9)
					{
						frameTime = 0;
						objetivo.x += 48;
						if (objetivo.x >= 144)
						{
							objetivo.x = 0;
						}
					}
				}
				if (event.key.keysym.sym == SDLK_d && posicion.x < 624)
				{
					posicion.x += 2;
					//objetivo.x = 0;
					objetivo.y = 144;
					frameTime++;
					if (FPS / frameTime <= 9)
					{
						frameTime = 0;
						objetivo.x += 48;
						if (objetivo.x >= 144)
						{
							objetivo.x = 0;
						}
					}
				}
				if (event.key.keysym.sym == SDLK_SPACE)
				{
					bomba = new Bomb(posicion.x, posicion.y);
					hasbomb = true;
				}

				playerRect = { posicion.x, posicion.y, 48, 48 };
				playerTarget = { objetivo.x, objetivo.y, 48, 48 };
			}
			if (player == player2)
			{
				if (event.key.keysym.sym == SDLK_UP && posicion.y > 128)
				{
					posicion.y -= 2;
					objetivo.y = 0;
					frameTime++;
					if (SCREEN_FPS / frameTime <= 9)
					{
						frameTime = 0;
						objetivo.x += 48;
						if (objetivo.x >= 144)
						{
							objetivo.x = 0;
						}
					}
				}
				if (event.key.keysym.sym == SDLK_LEFT && posicion.x > 48)
				{
					posicion.x -= 2;
					objetivo.y = 48;
					frameTime++;
					if (SCREEN_FPS / frameTime <= 9)
					{
						frameTime = 0;
						objetivo.x += 48;
						if (objetivo.x >= 144)
						{
							objetivo.x = 0;
						}
					}
				}
				if (event.key.keysym.sym == SDLK_DOWN && posicion.y < 608)
				{
					posicion.y += 2;
					objetivo.y = 96;
					frameTime++;
					if (SCREEN_FPS / frameTime <= 9)
					{
						frameTime = 0;
						objetivo.x += 48;
						if (objetivo.x >= 144)
						{
							objetivo.x = 0;
						}
					}
				}
				if (event.key.keysym.sym == SDLK_RIGHT && posicion.x < 624)
				{
					posicion.x += 2;
					objetivo.y = 144;
					frameTime++;
					if (SCREEN_FPS / frameTime <= 9)
					{
						frameTime = 0;
						objetivo.x += 48;
						if (objetivo.x >= 144)
						{
							objetivo.x = 0;
						}
					}
				}
				if (event.key.keysym.sym == SDLK_RCTRL)
				{
					bomba = new Bomb(posicion.x, posicion.y);
				}

				playerRect = { posicion.x, posicion.y, 48, 48 };
			}
		}
	}
}


