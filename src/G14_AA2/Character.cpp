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
				switch (event.key.keysym.sym)
				{
				case SDLK_w:
					if (position.y > 128)
					{
						position.y -= speed;
						objective.y = 0;
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
					break;
				case SDLK_a:
					if (position.x > 48)
					{
						position.x -= speed;
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
					break;
				case SDLK_s:
					if (position.y < 608)
					{
						position.y += speed;
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
					break;
				case SDLK_d:
					if (position.x < 624)
					{
						position.x += speed;
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
					break;
				case SDLK_SPACE:
					if (hasbomb == false)
					{
						bomb = new Bomb(position.x, position.y);
						hasbomb = true;
					}
					break;
				}

				playerRect = { position.x, position.y, 48, 48 };
				playerTarget = { objective.x, objective.y, 48, 48 };
				colision = false;
			}
			if (player == player2)
			{
				switch (event.key.keysym.sym)
				{
				case SDLK_UP:
					if (position.y > 128)
					{
						position.y -= speed;
						objective.y = 0;
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
					break;
				case SDLK_LEFT:
					if (position.x > 48)
					{
						position.x -= speed;
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
					break;
				case SDLK_DOWN:
					if (position.y < 608)
					{
						position.y += speed;
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
					break;
				case SDLK_RIGHT:
					if (position.x < 624)
					{
						position.x += speed;
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
					break;
				case SDLK_RCTRL:
					if (hasbomb == false)
					{
						bomb = new Bomb(position.x, position.y);
						hasbomb = true;
					}
					break;
				}
				playerRect = { position.x, position.y, 48, 48 };
				playerTarget = { objective.x, objective.y, 48, 48 };
				colision = false;
			}

				playerRect = { position.x, position.y, 48, 48 };
			}
		}
	}

