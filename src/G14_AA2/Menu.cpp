#include "Menu.h"



Menu::Menu()
{
	bgMenu = { 0,0,SCREEN_WIDTH, SCREEN_HEIGHT };
	PlaytextRect = {60, 350, medidaTextoPlay.x, medidaTextoPlay.y };
	RankingTextRect = { 60, 350, medidaTextoRanking.x, medidaTextoRanking.y };
	ExitTextRect = { 60, 350, medidaTextoExit.x, medidaTextoExit.y };
	//tmpSurf = { TTF_RenderText_Blended(play, "Play", SDL_Color{ 255, 150, 0, 255 }) };
}


Menu::~Menu()
{
}

void Menu::Update()
{
}

void Menu::Draw()
{
	Renderer::Instance()->Clear();
	Renderer::Instance()->PushImage(MENU_BG, bgMenu);
	Renderer::Instance()->PushImage(TEXT_PLAY, PlaytextRect);
	Renderer::Instance()->Render();
	
}

void Menu::HandleEvents()
{
}
