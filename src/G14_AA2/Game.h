#pragma once
#include "Menu.h"
#include "Play.h"
#include <string>


class Game
{
private:

public:
	Scene * scene;
	Play *jugar;
	void GameLoop();
	Game();
	~Game();
	

};

