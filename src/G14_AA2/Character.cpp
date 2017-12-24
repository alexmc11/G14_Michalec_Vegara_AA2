#include "Character.h"

Character::Character(playerTag Player)
{
	hasimmunity = false;
	lastkey = DEFAULT;
	points = 0;
	lives = 3;
	hasbomb = false;
	speed = 2;
	SDL_Event event;

	if (Player == player1)
	{
		position.x = 48;
		position.y = 128;
		objective.x = 48;
		objective.y = 96;
		playerRect = { position.x, position.y, 48, 48 };
		playerTarget = { objective.x, objective.y, 48, 48 };
	}
	else
	{
		position.x = 624;
		position.y = 608;
		objective.x = 0;
		objective.y = 0;
		playerRect = { position.x, position.y, 48, 48 };
		playerTarget = { objective.x, objective.y, 48, 48 };
	}
	player = Player;
	const Uint8* key = SDL_GetKeyboardState(NULL);

}

Character::~Character()
{
}


void Character::movement()
{
	while (SDL_PollEvent(&event) != 0)
	{
		if (event.type == SDL_KEYDOWN)
		{
			if (player == player1)
			{
				if (event.key.keysym.sym == SDLK_w && position.y > 128)
				{
					position.y -= speed;

					objective.y = 0;
					//objetivo.x = 0;
					frameTime++;
					if (FPS / frameTime <= 9)
					{
						frameTime = 0;
						objective.x += 48;
						if (objective.x >= 144)
						{
							objective.x = 0;
						}
					}
					lastkey = UP;
				}
				if (event.key.keysym.sym == SDLK_a && position.x > 48)
				{
					position.x -= speed;

					//objetivo.x = 0;
					objective.y = 48;
					frameTime++;
					if (FPS / frameTime <= 9)
					{
						frameTime = 0;
						objective.x += 48;
						if (objective.x >= 144)
						{
							objective.x = 0;
						}
					}
					lastkey = LEFT;
				}
				if (event.key.keysym.sym == SDLK_s && position.y < 608)
				{
					position.y += speed;

					//objetivo.x = 0;
					objective.y = 96;
					frameTime++;
					if (FPS / frameTime <= 9)
					{
						frameTime = 0;
						objective.x += 48;
						if (objective.x >= 144)
						{
							objective.x = 0;
						}
					}
					lastkey = DOWN;
				}
				if (event.key.keysym.sym == SDLK_d && position.x < 624)
				{
					position.x += speed;

					//objetivo.x = 0;
					objective.y = 144;
					frameTime++;
					if (FPS / frameTime <= 9)
					{
						frameTime = 0;
						objective.x += 48;
						if (objective.x >= 144)
						{
							objective.x = 0;
						}
					}
					lastkey = RIGHT;
				}
				if (event.key.keysym.sym == SDLK_SPACE)
				{
					if (hasbomb == false)
					{
						bomb = new Bomb(position.x, position.y);
						hasbomb = true;
					}

				}

				playerRect = { position.x, position.y, 48, 48 };
				playerTarget = { objective.x, objective.y, 48, 48 };
				colision = false;
			}
			if (player == player2)
			{
				if (event.key.keysym.sym == SDLK_UP && position.y > 128)
				{
					position.y -= speed;
					objective.y = 0;
					frameTime++;
					if (SCREEN_FPS / frameTime <= 9)
					{
						frameTime = 0;
						objective.x += 48;
						if (objective.x >= 144)
						{
							objective.x = 0;
						}
					}
				}
				if (event.key.keysym.sym == SDLK_LEFT && position.x > 48)
				{
					position.x -= speed;
					objective.y = 48;
					frameTime++;
					if (SCREEN_FPS / frameTime <= 9)
					{
						frameTime = 0;
						objective.x += 48;
						if (objective.x >= 144)
						{
							objective.x = 0;
						}
					}
				}
				if (event.key.keysym.sym == SDLK_DOWN && position.y < 608)
				{
					position.y += speed;
					objective.y = 96;
					frameTime++;
					if (SCREEN_FPS / frameTime <= 9)
					{
						frameTime = 0;
						objective.x += 48;
						if (objective.x >= 144)
						{
							objective.x = 0;
						}
					}
				}
				if (event.key.keysym.sym == SDLK_RIGHT && position.x < 624)
				{
					position.x += speed;
					objective.y = 144;
					frameTime++;
					if (SCREEN_FPS / frameTime <= 9)
					{
						frameTime = 0;
						objective.x += 48;
						if (objective.x >= 144)
						{
							objective.x = 0;
						}
					}
				}
				if (event.key.keysym.sym == SDLK_RCTRL)
				{
					bomb = new Bomb(position.x, position.y);
				}

				playerRect = { position.x, position.y, 48, 48 };
			}
		}
	}
}
