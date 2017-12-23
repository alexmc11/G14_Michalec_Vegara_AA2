#include "Menu.h"



Menu::Menu()
{
	bgMenu = { 0,0,SCREEN_WIDTH, SCREEN_HEIGHT };
	Play1textRect = {20, 250, medidaTextoPlay1.x, medidaTextoPlay1.y };
	Play2textRect = { 20, 350, medidaTextoPlay2.x, medidaTextoPlay2.y };
	RankingTextRect = { 20, 450, medidaTextoRanking.x, medidaTextoRanking.y };
	ExitTextRect = { 20, 550, medidaTextoExit.x, medidaTextoExit.y };
	TitleTextRect = { 20, 100, medidaTextoTitle.x, medidaTextoTitle.y };
	AudioTextRect = { 500, 650, medidaTextoAudio.x, medidaTextoAudio.y };
	audioStarted = false;
	mute = false;
	bool jugar1 = false;
	bool jugar2 = false;
	bool salir = false;
}


Menu::~Menu()
{
}

void Menu::Update()
{
	if (audioStarted == false)
	{
		Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 1024);
		Mix_Music *soundtrack{ Mix_LoadMUS("../../res/au/menu.mp3") };
		Mix_VolumeMusic(MIX_MAX_VOLUME / 4);
		Mix_PlayMusic(soundtrack, -1);
		audioStarted = true;
		muted = false;
		done = false;
	}
}

void Menu::Draw()
{
	Renderer::Instance()->Clear();
	Renderer::Instance()->PushImage(TEXT_PLAY1, Play1textRect);
	Renderer::Instance()->PushImage(TEXT_PLAY2, Play2textRect);
	Renderer::Instance()->PushImage(TEXT_RANKING, RankingTextRect);
	Renderer::Instance()->PushImage(TEXT_EXIT, ExitTextRect);
	Renderer::Instance()->PushImage(TEXT_TITLE, TitleTextRect);
	Renderer::Instance()->PushImage(TEXT_AUDIO, AudioTextRect);
	Renderer::Instance()->Render();
	
}

void Menu::HandleEvents()
{
	int static level;
	done = false;

	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_MOUSEMOTION:
			if (event.motion.x >= 20 && event.motion.x <= (medidaTextoPlay1.x) + 20 && event.motion.y >= 250 && event.motion.y <= medidaTextoPlay1.y + 250)
			{
				std::cout << "Plei1";
				jugar1 = true;
			}
			else
			{
				jugar1 = false;
			}
			if (event.motion.x >= 20 && event.motion.x <= (medidaTextoPlay1.x) + 20 && event.motion.y >= 350 && event.motion.y <= medidaTextoPlay1.y + 350)
			{
				std::cout << "Plei2";
				jugar2 = true;
			}
			else
			{
				jugar2 = false;
			}
			if (event.motion.x >= 20 && event.motion.x <= (medidaTextoRanking.x) + 20 && event.motion.y >= 450 && event.motion.y <= medidaTextoRanking.y + 450)
			{
				std::cout << "Ranquinc";
				ranking = true;
			}
			else
			{
				ranking = false;
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
			if (event.motion.x >= 500 && event.motion.x <= (medidaTextoAudio.x) + 500 && event.motion.y >= 650 && event.motion.y <= medidaTextoAudio.y + 650)
			{
				std::cout << "Audi";
				mute = true;
			}
			else
			{
				mute = false;
			}
			
			break;
		case SDL_MOUSEBUTTONDOWN:
			if (jugar1 == true)
			{
				
				Mix_CloseAudio();
				lvl = Level::LVL1;
				state = GameState::GOTO;
			}
			if (jugar2 == true)
			{
				Mix_CloseAudio();
				lvl = Level::LVL2;
				state = GameState::GOTO;
			}
			if (ranking == true)
			{
				lvl = Level::RANK;
				state = GameState::GOTO;
			}
			if (salir == true)
			{
				state = GameState::EXIT;
			}
			if (mute == true && muted == false && done == false)
			{
				Mix_PauseMusic();
				muted = true;
				std::cout << "muted";
				done = true;
			}
			if (mute == true && muted == true &&  done == false)
			{
				Mix_ResumeMusic();
				muted = false;
				std::cout << "unmuted";
				done = true;
			}
		default:;
		}
	}
}
