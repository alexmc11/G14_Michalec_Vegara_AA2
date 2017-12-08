#include "Character.h"


Character::Character()
{
	SDL_Event event;

	posicion1.x == 0;
	posicion2.y == 0;

	posicion2.x == 500;
	posicion2.y == 500;

	//Player1

	frameWidth = image1Size.x / 2;

	frameHeight = image1Size.y / 4;

	player1Rect.x = player1Rect.y = 0;

	player1Position.x = player1Position.y = 0;

	player1Rect.h = 48;

	player1Rect.w = 48;

	//Player2

	frame2Width = image2Size.x / 2;

	frame2Height = image2Size.y / 4;

	player2Rect.x = player2Rect.y = 0;

	player2Position.x = player2Position.y = 0;

	player2Rect.h = 48;
	
	player2Rect.w = 48;

}

Character::~Character()
{
}

void Character::movement()
{
	#pragma region "Player 1 Movement"
		if (event.key.keysym.sym == SDLK_w && posicion1.y >= 170)
		{
			posicion1.y -= 2;
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
		if (event.key.keysym.sym == SDLK_a && posicion1.x >= 0)
		{
			posicion1.x -= 2;
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
		if (event.key.keysym.sym == SDLK_s && posicion1.y <= (SCREEN_HEIGHT - frameHeight))
		{
			posicion1.y += 2;
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
		if (event.key.keysym.sym == SDLK_d && posicion1.x <= (SCREEN_WIDTH - frameWidth))
		{
			posicion1.x += 2;
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
	#pragma endregion

	#pragma region "Player 2 Movement"
		if (event.key.keysym.sym == SDLK_UP && posicion2.y >= 170)
		{
			posicion2.y -= 2;
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
		if (event.key.keysym.sym == SDLK_LEFT && posicion2.x >= 0)
		{
			posicion2.x -= 2;
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
		if (event.key.keysym.sym == SDLK_DOWN && posicion2.y <= (SCREEN_HEIGHT - frameHeight))
		{
			posicion2.y += 2;
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
		if (event.key.keysym.sym == SDLK_RIGHT && posicion2.x <= (SCREEN_WIDTH - frameWidth))
		{
			posicion2.x += 2;
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
	#pragma endregion
}


