#include "Ranking.h"



Ranking::Ranking()
{
	returnMenuRect = { 20, 650, medidaTextMenu.x, medidaTextMenu.y };
	returnMenu = false;
}


Ranking::~Ranking()
{
}

void Ranking::Update()
{
}

void Ranking::Draw()
{
	Renderer::Instance()->Clear();
	Renderer::Instance()->PushImage(TEXT_RETURNMENU, returnMenuRect);
	Renderer::Instance()->Render();
}

void Ranking::HandleEvents()
{
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_MOUSEMOTION:	
			if (event.motion.x >= 20 && event.motion.x <= (medidaTextMenu.x) + 20 && event.motion.y >= 650 && event.motion.y <= medidaTextMenu.y + 650)
			{
				std::cout << "return";
				returnMenu = true;
			}
			else
			{
				returnMenu = false;
			}

			break;
		case SDL_MOUSEBUTTONDOWN:
			if (returnMenu == true)
			{
				state = GameState::GOTO;
			}
		default:;
		}
	}
}
