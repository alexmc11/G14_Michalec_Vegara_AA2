#pragma once
#include <SDL.h>
#include "Renderer.h"
#include "../../dep/inc/XML/rapidxml.hpp"
#include "../../dep/inc/XML/rapidxml_utils.hpp"
#include "../../dep/inc/XML/rapidxml_iterators.hpp"
#include "../../dep/inc/XML/rapidxml_print.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <sstream>

struct FixBrick
{
	SDL_Rect fixBrickRect, fixBrickTarget;
};

struct DestructibleBrick
{
	SDL_Rect desBrickRect, desBrickTarget;
};

class Map
{
public:

	Map();

	~Map();

	int time;
	int livesNum;

	std::vector<FixBrick> FixBricks;
	std::vector<DestructibleBrick> DesBricks;

	void ReadXML1();
	void ReadXML2();

	void DrawFixBricks();
	void DrawDesBricks();

};

