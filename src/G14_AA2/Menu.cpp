#include "Menu.h"



Menu::Menu()
{
	bgMenu = { 0,0,SCREEN_WIDTH, SCREEN_HEIGHT };
	Play1textRect = {20, 250, PlayTextSize1.x, PlayTextSize1.y };
	Play2textRect = { 20, 350, PlayTextSize2.x, PlayTextSize2.y };
	RankingTextRect = { 20, 450, RankingTextSize.x, RankingTextSize.y };
	ExitTextRect = { 20, 550, ExitTextSize.x, ExitTextSize.y };
	TitleTextRect = { 20, 100, TitleTextSize.x, TitleTextSize.y };
	AudioTextRect = { 500, 650, AudioTextSize.x, AudioTextSize.y };
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
			if (event.motion.x >= 20 && event.motion.x <= (PlayTextSize1.x) + 20 && event.motion.y >= 250 && event.motion.y <= PlayTextSize1.y + 250)
			{
				play1 = true;
			}
			else
			{
				play1 = false;
			}
			if (event.motion.x >= 20 && event.motion.x <= (PlayTextSize2.x) + 20 && event.motion.y >= 350 && event.motion.y <= PlayTextSize2.y + 350)
			{
				play2 = true;
			}
			else
			{
				play2 = false;
			}
			if (event.motion.x >= 20 && event.motion.x <= (RankingTextSize.x) + 20 && event.motion.y >= 450 && event.motion.y <= RankingTextSize.y + 450)
			{
				ranking = true;
			}
			else
			{
				ranking = false;
			}
			if (event.motion.x >= 20 && event.motion.x <= (ExitTextSize.x) + 20 && event.motion.y >= 550 && event.motion.y <= ExitTextSize.y + 550)
			{
				exit = true;
			}
			else
			{
				exit = false;
			}
			if (event.motion.x >= 500 && event.motion.x <= (AudioTextSize.x) + 500 && event.motion.y >= 650 && event.motion.y <= AudioTextSize.y + 650)
			{
				mute = true;
			}
			else
			{
				mute = false;
			}
			
			break;
		case SDL_MOUSEBUTTONDOWN:
			if (play1 == true)
			{
				
				Mix_CloseAudio();
				lvl = Level::LVL1;
				state = GameState::GOTO;
			}
			if (play2 == true)
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
			if (exit == true)
			{
				state = GameState::EXIT;
			}
			if (mute == true && muted == false && done == false)
			{
				Mix_PauseMusic();
				muted = true;
				std::cout << "muted" << std::endl;
				done = true;
			}
			if (mute == true && muted == true &&  done == false)
			{
				Mix_ResumeMusic();
				muted = false;
				std::cout << "unmuted" << std::endl;
				done = true;
			}
		default:;
		}
	}
}
