#include "Menu.h"



Menu::Menu()
{
	bgMenu = { 0,0,SCREEN_WIDTH, SCREEN_HEIGHT };
	//textRect = { 100, 50, tmpSurf->w, tmpSurf->h };
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
	Renderer::Instance()->PushImage(TEXT_PLAY, textRect);
	Renderer::Instance()->Render();
	
}

void Menu::HandleEvents()
{
}
