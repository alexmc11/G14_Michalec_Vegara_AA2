#include "Menu.h"



Menu::Menu()
{
	bgMenu = { 0,0,SCREEN_WIDTH, SCREEN_HEIGHT };
	PlaytextRect = {20, 350, medidaTextoPlay.x, medidaTextoPlay.y };
	RankingTextRect = { 20, 450, medidaTextoRanking.x, medidaTextoRanking.y };
	ExitTextRect = { 20, 550, medidaTextoExit.x, medidaTextoExit.y };
	TitleTextRect = { 20, 100, medidaTextoTitle.x, medidaTextoTitle.y };
	audioStarted = false;
}


Menu::~Menu()
{
}

void Menu::Update()
{
	/*if (audioStarted == false)
	{
		Mix_OpenAudio(Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 1024);
	}*/
}

void Menu::Draw()
{
	Renderer::Instance()->Clear();
	Renderer::Instance()->PushImage(TEXT_PLAY, PlaytextRect);
	Renderer::Instance()->PushImage(TEXT_RANKING, RankingTextRect);
	Renderer::Instance()->PushImage(TEXT_EXIT, ExitTextRect);
	Renderer::Instance()->PushImage(TEXT_TITLE, TitleTextRect);
	Renderer::Instance()->Render();
	
}

void Menu::HandleEvents()
{
	bool jugar = false;
	bool salir = false;
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_MOUSEMOTION:
			if (event.motion.x >= 20 && event.motion.x <= (medidaTextoPlay.x) + 20 && event.motion.y >= 350 && event.motion.y <= medidaTextoPlay.y + 350)
			{
				std::cout << "Plei";
				jugar = true;
			}
			else
			{
				jugar = false;
			}
			if (event.motion.x >= 20 && event.motion.x <= (medidaTextoRanking.x) + 20 && event.motion.y >= 450 && event.motion.y <= medidaTextoRanking.y + 450)
			{
				std::cout << "Ranquinc";
			}
			if (event.motion.x >= 20 && event.motion.x <= (medidaTextoExit.x) + 20 && event.motion.y >= 550 && event.motion.y <= medidaTextoExit.y + 550)
			{
				std::cout << "Ecsit";
				salir = true;
			}
			else
			{
				salir = false;
			}
			break;
		case SDL_MOUSEBUTTONDOWN:
			if (jugar == true)
			{
				state = GameState::GOTO;
			}
			if (salir == true)
			{
				state = GameState::EXIT;
			}
		default:;
		}
	}
}
