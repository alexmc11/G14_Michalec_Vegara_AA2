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

	//Player1

	frameWidth = image1Size.x / 2;

	frameHeight = image1Size.y / 4;

	player1Rect.x = player1Rect.y = 0;

	player1Position.h = player1Rect.h = frameHeight;

	player1Position.w = player1Rect.w = frameWidth;

	//Player2

	frame2Width = image2Size.x / 2;

	frame2Height = image2Size.y / 4;

	player2Rect.x = player2Rect.y = 0;

	player2Position.h = player2Rect.h = frame2Height;

	player2Position.w = player2Rect.w = frame2Width;

}

Character::~Character()
{
}

void Character::movement(playerTag player)
{
	#pragma region "Player 1 Movement"
	if (player == player1)
	{
		if (event.key.keysym.sym == SDLK_w && playerPosition.y >= 170)
		{
			playerPosition.y -= 2;
			player1Rect.y = frameHeight;
			player1Rect.x = frameWidth;
			frameTime++;
			if (FPS / frameTime <= 9)
			{
				frameTime = 0;
				player1Rect.x += frameWidth;
				if (player1Rect.x >= image1Size.x)
				{
					player1Rect.x = 0;
				}
			}
		}
		if (event.key.keysym.sym == SDLK_a && playerPosition.x >= 0)
		{
			playerPosition.x -= 2;
			player1Rect.y = frameHeight * 2;
			player1Rect.x = frameWidth;
			frameTime++;
			if (FPS / frameTime <= 9)
			{
				frameTime = 0;
				player1Rect.x += frameWidth;
				if (player1Rect.x >= image1Size.x)
				{
					player1Rect.x = 0;
				}
			}
		}
		if (event.key.keysym.sym == SDLK_s && playerPosition.y <= (SCREEN_HEIGHT - frameHeight))
		{
			playerPosition.y += 2;
			player1Rect.y = frameHeight * 3;
			player1Rect.x = frameWidth;
			frameTime++;
			if (FPS / frameTime <= 9)
			{
				frameTime = 0;
				player1Rect.x += frameWidth;
				if (player1Rect.x >= image1Size.x)
				{
					player1Rect.x = 0;
				}
			}
		}
		if (event.key.keysym.sym == SDLK_d && playerPosition.x <= (SCREEN_WIDTH - frameWidth))
		{
			playerPosition.x += 2;
			player1Rect.y = frameHeight * 4;
			player1Rect.x = frameWidth;
			frameTime++;
			if (FPS / frameTime <= 9)
			{
				frameTime = 0;
				player1Rect.x += frameWidth;
				if (player1Rect.x >= textWidth)
				{
					player1Rect.x = 0;
				}
			}
		}
	}
	#pragma endregion

	#pragma region "Player 2 Movement"
	if (player == player2)
	{
		if (event.key.keysym.sym == SDLK_UP && playerPosition.y >= 170)
		{
			playerPosition.y -= 2;
			player2Rect.y = frame2Height;
			player2Rect.x = frame2Width;
			frameTime++;
			if (FPS / frameTime <= 9)
			{
				frameTime = 0;
				player2Rect.x += frame2Width;
				if (player2Rect.x >= image2Size.x)
				{
					player2Rect.x = 0;
				}
			}
		}
		if (event.key.keysym.sym == SDLK_LEFT && playerPosition.x >= 0)
		{
			playerPosition.x -= 2;
			player2Rect.y = frame2Height * 2;
			player2Rect.x = frame2Width;
			frameTime++;
			if (FPS / frameTime <= 9)
			{
				frameTime = 0;
				player2Rect.x += frame2Width;
				if (player2Rect.x >= image2Size.x)
				{
					player2Rect.x = 0;
				}
			}
		}
		if (event.key.keysym.sym == SDLK_DOWN && playerPosition.y <= (SCREEN_HEIGHT - frameHeight))
		{
			playerPosition.y += 2;
			player2Rect.y = frame2Height * 3;
			player2Rect.x = frame2Width;
			frameTime++;
			if (FPS / frameTime <= 9)
			{
				frameTime = 0;
				player2Rect.x += frame2Width;
				if (player2Rect.x >= image2Size.x)
				{
					player2Rect.x = 0;
				}
			}
		}
		if (event.key.keysym.sym == SDLK_RIGHT && playerPosition.x <= (SCREEN_WIDTH - frameWidth))
		{
			playerPosition.x += 2;
			player2Rect.y = frame2Height * 4;
			player2Rect.x = frame2Width;
			frameTime++;
			if (FPS / frameTime <= 9)
			{
				frameTime = 0;
				player2Rect.x += frame2Width;
				if (player2Rect.x >= text2Width)
				{
					player2Rect.x = 0;
				}
			}
		}
	}
	#pragma endregion
}


