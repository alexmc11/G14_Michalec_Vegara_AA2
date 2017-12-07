#include "Game.h"


Game::Game()
{
	//CREATE TEXTS
	Text play{ TEXT_PLAY, "PLAY",{ 0, 255, 0, 255 }, 0, 0 };
	Text ranking{ TEXT_PLAY, "RANKING",{ 0, 255, 0, 255 }, 0, 0 };
	Text exit{ TEXT_PLAY, "EXIT",{ 0, 255, 0, 255 }, 0, 0 };
	Renderer::Instance()->LoadFont({ GAME_OVER80, PATH_FONT, 80 });
	Renderer::Instance()->LoadTextureText(GAME_OVER80, play);
	Renderer::Instance()->LoadTextureText(GAME_OVER80, exit);
	Renderer::Instance()->LoadTextureText(GAME_OVER80, ranking);

	//CREATE TEXTURES
	Renderer::Instance()->LoadTexture(MENU_BG, PATH_BGMENU);
	
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

