#include "Character.h"


bool Character::colisiones(SDL_Rect* A, SDL_Rect* B)
{
	if (A->y >= (B->y + B->h))
	{
		return 0;
	}
	if (A->x >= (B->x + B->w))
	{
		return 0;
	}
	if ((A->y + A->h) <= B->y)
	{
		return 0;
	}
	if ((A->x + A->w) <= B->x)
	{
		return 0;
	}

	return 1;
	
}

bool Character::iteradorcolisiones()
{
	for (int i = 0; i < mapa.MurosFijos.size(); i++)
	{
		if (colisiones(&mapa.MurosFijos[i].fixBrickRect, &playerRect) == 1)
		{
			return true;
		}
	}
	for (int i = 0; i < mapa.MurosDestruibles.size(); i++)
	{
		if (colisiones(&mapa.MurosDestruibles[i].destructibleBrickRect, &playerRect) == 1)
		{
			return true;
		}
	}
	return false;
}


Character::Character(playerTag jugador)
{
	lastkey = DEFAULT;
	points = 0;
	vidas = 3;
	hasbomb = false;
	SDL_Event event;

	timer = 0;
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
	const Uint8* key = SDL_GetKeyboardState(NULL);

}

Character::~Character()
{
}

void Character::collisionMovement()
{
	if (lastkey == UP)
	{
		if (iteradorcolisiones() == true)
		{
			posicion.y += 2;
			lastkey = DEFAULT;
		}

	}
	if (lastkey == DOWN)
	{
		if (iteradorcolisiones() == true)
		{
			posicion.y -= 2;
			lastkey = DEFAULT;
		}
	}
	if (lastkey == LEFT)
	{
		if (iteradorcolisiones() == true)
		{
			posicion.x += 2;
			lastkey = DEFAULT;
		}
	}
	if (lastkey == RIGHT)
	{
		if (iteradorcolisiones() == true)
		{
			posicion.x -= 2;
			lastkey = DEFAULT;
		}
	}
}
void Character::movement()
{
	while (SDL_PollEvent(&event) != 0)
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
					lastkey = UP;
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
					lastkey = LEFT;
				}
				if (event.key.keysym.sym == SDLK_s && posicion.y < 608)
				{
					posicion.y += 2;

					//objetivo.x = 0;
					objetivo.y = 96;
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
					lastkey = DOWN;
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
					lastkey = RIGHT;
				}
				if (event.key.keysym.sym == SDLK_SPACE)
				{
					if (hasbomb == false)
					{
						bomba = new Bomb(posicion.x, posicion.y);
						hasbomb = true;
					}

				}

				playerRect = { posicion.x, posicion.y, 48, 48 };
				playerTarget = { objetivo.x, objetivo.y, 48, 48 };
				colision = false;
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
