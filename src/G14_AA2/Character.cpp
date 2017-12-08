#include "Character.h"


Character::Character(playerTag player)
{
	SDL_Event event;
	if (player == player1)
	{
		playerPosition.x == 0;
		playerPosition.y == 0;
	}
	if (player == player2)
	{
		playerPosition.x == 500;
		playerPosition.y == 500;
	}
}

Character::~Character()
{
}

void Character::movement(playerTag player)
{
	if (player == player1)
	{
		if (event.key.keysym.sym == SDLK_w && playerPosition.y >= 170)
		{
			playerPosition.y -= 2;
			playerRect.y = frameHeight * 7;
			playerRect.x = frameWidth * 3;
			frameTime++;
			if (FPS / frameTime <= 9)
			{
				frameTime = 0;
				playerRect.x += frameWidth;
				if (playerRect.x >= textWidth)
				{
					playerRect.x = 0;
				}
			}
		}
		if (event.key.keysym.sym == SDLK_a && playerPosition.x >= 0)
		{
			playerPosition.x -= 2;
			playerRect.y = frameHeight * 5;
			playerRect.x = frameWidth * 3;
			frameTime++;
			if (FPS / frameTime <= 9)
			{
				frameTime = 0;
				playerRect.x += frameWidth;
				if (playerRect.x >= textWidth)
				{
					playerRect.x = 0;
				}
			}
		}
		if (event.key.keysym.sym == SDLK_s && playerPosition.y <= (SCREEN_HEIGHT - frameHeight))
		{
			playerPosition.y += 2;
			playerRect.y = frameHeight * 4;
			playerRect.x = frameWidth * 3;
			frameTime++;
			if (FPS / frameTime <= 9)
			{
				frameTime = 0;
				playerRect.x += frameWidth;
				if (playerRect.x >= textWidth)
				{
					playerRect.x = 0;
				}
			}
		}
		if (event.key.keysym.sym == SDLK_d && playerPosition.x <= (SCREEN_WIDTH - frameWidth))
		{
			playerPosition.x += 2;
			playerRect.y = frameHeight * 6;
			playerRect.x = frameWidth * 3;
			frameTime++;
			if (FPS / frameTime <= 9)
			{
				frameTime = 0;
				playerRect.x += frameWidth;
				if (playerRect.x >= textWidth)
				{
					playerRect.x = 0;
				}
			}
		}
	}
	if (player == player2)
	{
		if (event.key.keysym.sym == SDLK_UP && playerPosition.y >= 170)
		{
			playerPosition.y -= 2;
			playerRect.y = frameHeight * 7;
			playerRect.x = frameWidth * 3;
			frameTime++;
			if (FPS / frameTime <= 9)
			{
				frameTime = 0;
				playerRect.x += frameWidth;
				if (playerRect.x >= textWidth)
				{
					playerRect.x = 0;
				}
			}
		}
		if (event.key.keysym.sym == SDLK_LEFT && playerPosition.x >= 0)
		{
			playerPosition.x -= 2;
			playerRect.y = frameHeight * 5;
			playerRect.x = frameWidth * 3;
			frameTime++;
			if (FPS / frameTime <= 9)
			{
				frameTime = 0;
				playerRect.x += frameWidth;
				if (playerRect.x >= textWidth)
				{
					playerRect.x = 0;
				}
			}
		}
		if (event.key.keysym.sym == SDLK_DOWN && playerPosition.y <= (SCREEN_HEIGHT - frameHeight))
		{
			playerPosition.y += 2;
			playerRect.y = frameHeight * 4;
			playerRect.x = frameWidth * 3;
			frameTime++;
			if (FPS / frameTime <= 9)
			{
				frameTime = 0;
				playerRect.x += frameWidth;
				if (playerRect.x >= textWidth)
				{
					playerRect.x = 0;
				}
			}
		}
		if (event.key.keysym.sym == SDLK_RIGHT && playerPosition.x <= (SCREEN_WIDTH - frameWidth))
		{
			playerPosition.x += 2;
			playerRect.y = frameHeight * 6;
			playerRect.x = frameWidth * 3;
			frameTime++;
			if (FPS / frameTime <= 9)
			{
				frameTime = 0;
				playerRect.x += frameWidth;
				if (playerRect.x >= textWidth)
				{
					playerRect.x = 0;
				}
			}
		}
	}
}


