#include "Character.h"


Character::Character(playerTag jugador)
{
	SDL_Event event;

	if (jugador == player1)
	{
		posicion.x = 48;
		posicion.y = 128;
		playerRect = { posicion.x, posicion.y, 48, 48 };
		playerTarget = { 48, 96, 48, 48 };
	}
	else
	{
		posicion.x = 624;
		posicion.y = 608;
		playerRect = { posicion.x, posicion.y, 48, 48 };
		playerTarget = { 0, 0, 48, 48 };
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
					std::cout << posicion.y << std::endl;
					playerRect.y = frameHeight;
					playerRect.x = frameWidth;
					frameTime++;
					if (SCREEN_FPS / frameTime <= 9)
					{
						frameTime = 0;
						playerRect.x += frameWidth;
						if (playerRect.x >= image1Size.x)
						{
							playerRect.x = 0;
						}
					}
				}
				if (event.key.keysym.sym == SDLK_a && posicion.x > 48)
				{
					posicion.x -= 2;
					std::cout << posicion.x << std::endl;
					playerRect.y = frameHeight * 2;
					playerRect.x = frameWidth;
					frameTime++;
					if (SCREEN_FPS / frameTime <= 9)
					{
						frameTime = 0;
						playerRect.x += frameWidth;
						if (playerRect.x >= image1Size.x)
						{
							playerRect.x = 0;
						}
					}
				}
				if (event.key.keysym.sym == SDLK_s && posicion.y < 608)
				{
					posicion.y += 2;
					std::cout << posicion.y << std::endl;
					playerRect.y = frameHeight * 3;
					playerRect.x = frameWidth;
					frameTime++;
					if (SCREEN_FPS / frameTime <= 9)
					{
						frameTime = 0;
						playerRect.x += frameWidth;
						if (playerRect.x >= image1Size.x)
						{
							playerRect.x = 0;
						}
					}
				}
				if (event.key.keysym.sym == SDLK_d && posicion.x < 624)
				{
					posicion.x += 2;
					std::cout << posicion.x << std::endl;
					playerRect.y = frameHeight * 4;
					playerRect.x = frameWidth;
					frameTime++;
					if (SCREEN_FPS / frameTime <= 9)
					{
						frameTime = 0;
						playerRect.x += frameWidth;
						if (playerRect.x >= textWidth)
						{
							playerRect.x = 0;
						}
					}
				}
				if (event.key.keysym.sym == SDLK_SPACE)
				{
					bomba = new Bomb(posicion.x, posicion.y);
					cantidadBombas.push_back(bomba);
				}

				playerRect = { posicion.x, posicion.y, 48, 48 };
			}
		}
	}
	if (SDL_PollEvent(&event2))
	{
		if (event2.type == SDL_KEYDOWN)
		{
			if (player == player2)
			{
				if (event.key.keysym.sym == SDLK_UP && posicion.y > 128)
				{
					posicion.y -= 2;
					std::cout << posicion.y << std::endl;
					playerRect.y = frameHeight;
					playerRect.x = frameWidth;
					frameTime++;
					if (SCREEN_FPS / frameTime <= 9)
					{
						frameTime = 0;
						playerRect.x += frameWidth;
						if (playerRect.x >= image1Size.x)
						{
							playerRect.x = 0;
						}
					}
				}
				if (event.key.keysym.sym == SDLK_LEFT && posicion.x > 48)
				{
					posicion.x -= 2;
					std::cout << posicion.x << std::endl;
					playerRect.y = frameHeight * 2;
					playerRect.x = frameWidth;
					frameTime++;
					if (SCREEN_FPS / frameTime <= 9)
					{
						frameTime = 0;
						playerRect.x += frameWidth;
						if (playerRect.x >= image1Size.x)
						{
							playerRect.x = 0;
						}
					}
				}
				if (event.key.keysym.sym == SDLK_DOWN && posicion.y < 608)
				{
					posicion.y += 2;
					std::cout << posicion.y << std::endl;
					playerRect.y = frameHeight * 3;
					playerRect.x = frameWidth;
					frameTime++;
					if (SCREEN_FPS / frameTime <= 9)
					{
						frameTime = 0;
						playerRect.x += frameWidth;
						if (playerRect.x >= image1Size.x)
						{
							playerRect.x = 0;
						}
					}
				}
				if (event.key.keysym.sym == SDLK_RIGHT && posicion.x < 624)
				{
					posicion.x += 2;
					std::cout << posicion.x << std::endl;
					playerRect.y = frameHeight * 4;
					playerRect.x = frameWidth;
					frameTime++;
					if (SCREEN_FPS / frameTime <= 9)
					{
						frameTime = 0;
						playerRect.x += frameWidth;
						if (playerRect.x >= textWidth)
						{
							playerRect.x = 0;
						}
					}
				}
				if (event.key.keysym.sym == SDLK_RCTRL)
				{
					new Bomb(posicion.x, posicion.y);
				}

				playerRect = { posicion.x, posicion.y, 48, 48 };
			}
		}
	}
}


