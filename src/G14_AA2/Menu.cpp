#include "Menu.h"



Menu::Menu()
{
	bgMenu = { 0,0,SCREEN_WIDTH, SCREEN_HEIGHT };
	PlaytextRect = {20, 350, medidaTextoPlay.x, medidaTextoPlay.y };
	RankingTextRect = { 20, 450, medidaTextoRanking.x, medidaTextoRanking.y };
	ExitTextRect = { 20, 550, medidaTextoExit.x, medidaTextoExit.y };
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
	Renderer::Instance()->PushImage(TEXT_RANKING, RankingTextRect);
	Renderer::Instance()->PushImage(TEXT_EXIT, ExitTextRect);
	Renderer::Instance()->Render();
	
}

void Menu::HandleEvents()
{
}
