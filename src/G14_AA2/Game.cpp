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
	while (scene->state != GameState::EXIT:) 
	{/*
			switch (scene->state)
			{
			case GameState
				m_currentScene->EventHandle();
				m_currentScene->Update();
				m_currentScene->Draw();
				break;

			case SceneState::EXIT:
				switch (m_gameState)
				{
				case GameState::MENU:
					delete m_currentScene;
					m_currentScene = nullptr;
					m_gameState = GameState::EXIT;
					break;
				case GameState::PLAY:
					delete m_currentScene;
					m_currentScene = new Menu();
					break;
				default:
					break;
				}
				break;

			case SceneState::GOTO:
				switch (m_gameState)
				{
				case GameState::MENU:
					delete m_currentScene;
					m_currentScene = new Play();
					m_gameState = GameState::PLAY;
					break;
				case GameState::PLAY:
					delete m_currentScene;
					m_currentScene = new Menu();
					m_gameState = GameState::MENU;
					break;
				default:
					break;
				}
				break;
			default:
				break;
			}*/


	}
}

