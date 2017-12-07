#include "Menu.h"



Menu::Menu()
{
	bgMenu = { 0,0,SCREEN_WIDTH, SCREEN_HEIGHT };
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
	Renderer::Instance()->Render();
	
}

void Menu::HandleEvents()
{
}
