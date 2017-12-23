#include "Game.h"



Game::Game()
{
	//Backgrounds
	Renderer::Instance()->LoadTexture(PLAY_BG, PATH_PLAY);
	//CREATE TEXTS
	Text play1{ TEXT_PLAY1, "PLAY LVL 1",{ 255, 255, 255, 255 }, 0, 0 };
	Text play2{ TEXT_PLAY2, "PLAY LVL 2",{ 255, 255, 255, 255 }, 0, 0 };
	Text ranking{ TEXT_RANKING, "RANKING",{ 255, 255, 255, 255 }, 0, 0 };
	Text exit{ TEXT_EXIT, "EXIT",{ 255, 255, 255, 255 }, 0, 0 };
	Text bomberman{ TEXT_TITLE, "BOMBERMAN", {255, 255, 255, 255}, 0, 0 };
	Text audio{ TEXT_AUDIO, "AUDIO ON/OFF", {255, 255, 255, 255}, 0, 0 };
	Text vidas{ TEXT_VIDAS, "VIDAS P1: ",{ 0, 0, 255, 255 }, 0, 0 };
	Text vidas2{ TEXT_VIDAS2, "VIDAS P2: ",{ 255, 0, 0, 255 }, 0, 0 };
	

	Renderer::Instance()->LoadFont({ GAME_OVER80, PATH_FONT, 130 });
	Renderer::Instance()->LoadFont({ GAME_OVERTITLE, PATH_FONT, 200 });
	Renderer::Instance()->LoadFont({ GAME_OVERAUDIO, PATH_FONT, 70 });
	Renderer::Instance()->LoadFont({ GAME_OVERVIDAS, PATH_FONT, 70 });
	Renderer::Instance()->LoadFont({ GAME_OVERVIDAS2, PATH_FONT, 70 });
	Renderer::Instance()->LoadTextureText(GAME_OVER80, play1);
	Renderer::Instance()->LoadTextureText(GAME_OVER80, play2);
	Renderer::Instance()->LoadTextureText(GAME_OVER80, exit);
	Renderer::Instance()->LoadTextureText(GAME_OVER80, ranking);
	Renderer::Instance()->LoadTextureText(GAME_OVERTITLE, bomberman);
	Renderer::Instance()->LoadTextureText(GAME_OVERAUDIO, audio);
	Renderer::Instance()->LoadTextureText(GAME_OVERVIDAS, vidas);
	Renderer::Instance()->LoadTextureText(GAME_OVERVIDAS2, vidas2);
	

	//CREATE TEXTURES
	Renderer::Instance()->LoadTexture(PLAYER1_SPRITE, PATH_PLAYER1);
	Renderer::Instance()->LoadTexture(PLAYER2_SPRITE, PATH_PLAYER2);
	Renderer::Instance()->LoadTexture(ITEMS_SPRITE, PATH_ITEMS);
	Renderer::Instance()->LoadTexture(EXPLOSION_SPRITE, PATH_EXPLOSION);
	scene = new Menu();
	int hola = 1;
}

Game::~Game()
{
}

void Game::GameLoop()
{
	scene->state = GameState::MENU;
	scene->escenActual = CurrentScene::MENIU;
	while (scene->state != GameState::EXIT) 
	{
	
			switch (scene->state)
			{
			case GameState::MENU:
				scene->escenActual = CurrentScene::MENIU;
				scene->HandleEvents();
				scene->Update();
				scene->Draw();
				break;

			case GameState::PLAY:
				scene->escenActual = CurrentScene::PLEI;
				scene->HandleEvents();
				scene->Update();
				scene->Draw();
				break;

			case GameState::RANKING:
				scene->escenActual = CurrentScene::RANQUINC;
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
				switch (scene->escenActual)
				{
				case CurrentScene::MENIU:
					if (scene->lvl == Level::LVL1)
					{
						delete scene;
						scene = new Play(lvl1);
						scene->state = GameState::PLAY;
					}
					else if (scene->lvl == Level::LVL2)
					{
						delete scene;
						scene = new Play(lvl2);
						scene->state = GameState::PLAY;
					}
					else if (scene->lvl == Level::RANK)
					{
						delete scene;
						scene = new Ranking();
						scene->state = GameState::RANKING;
					}
					break;
				case CurrentScene::PLEI:
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

