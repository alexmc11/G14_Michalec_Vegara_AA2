#pragma once
#include "Menu.h"
#include "Play.h"
#include <string>


class Game
{
private:

public:
	Menu bigmac;
	Scene * scene;
	void GameLoop();
	Game();
	~Game();
	

};

