#include "Game.h"


Game::Game()
{
	//Backgrounds
	Renderer::Instance()->LoadTexture(MENU_BG, PATH_BGMENU);
	Renderer::Instance()->LoadTexture(PLAY_BG, PATH_PLAY);

	//CREATE TEXTS
	Text play{ TEXT_PLAY, "PLAY",{ 0, 255, 0, 255 }, 0, 0 };
	Text ranking{ TEXT_RANKING, "RANKING",{ 0, 255, 0, 255 }, 0, 0 };
	Text exit{ TEXT_EXIT, "EXIT",{ 0, 255, 0, 255 }, 0, 0 };
	Renderer::Instance()->LoadFont({ GAME_OVER80, PATH_FONT, 130 });
	Renderer::Instance()->LoadTextureText(GAME_OVER80, play);
	Renderer::Instance()->LoadTextureText(GAME_OVER80, exit);
	Renderer::Instance()->LoadTextureText(GAME_OVER80, ranking);

	//CREATE TEXTURES
	Renderer::Instance()->LoadTexture(VIDAS1_SPRITE, PATH_VIDAS1);
	Renderer::Instance()->LoadTexture(VIDAS2_SPRITE, PATH_VIDAS2);
	Renderer::Instance()->LoadTexture(RECTANGULO_SPRITE, PATH_RECTANGULO);
	Renderer::Instance()->LoadTexture(PLAYER1_SPRITE, PATH_PLAYER1);
	Renderer::Instance()->LoadTexture(PLAYER2_SPRITE, PATH_PLAYER2);
	
	scene = new Menu();
}

Game::~Game()
{
}

void Game::GameLoop()
{
	scene->state = GameState::MENU;
	while (scene->state != GameState::EXIT) 
	{
			switch (scene->state)
			{
			case GameState::MENU:
				scene->HandleEvents();
				scene->Update();
				scene->Draw();
				break;

			case GameState::EXIT:
				switch (scene->state)
				{
				case GameState::MENU:
					delete scene;
					scene = nullptr;
					scene->state = GameState::EXIT;
					break;
				case GameState::PLAY:
					delete scene;
					scene = new Menu();
					break;
				default:
					break;
				}
				break;

			case GameState::GOTO:
				switch (scene->state)
				{
				case GameState::MENU:
					delete scene;
					scene = new Play();
					scene->state = GameState::PLAY;
					break;
				case GameState::PLAY:
					delete scene;
					scene = new Menu();
					scene->state = GameState::MENU;
					break;
				default:
					break;
				}
				break;
			default:
				break;
			}


	}
}

