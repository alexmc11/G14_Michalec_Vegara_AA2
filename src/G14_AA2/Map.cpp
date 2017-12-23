#include "Map.h"



Map::Map()
{	
}

void Map::ReadXML1()
{
	rapidxml::xml_document<> doc;
	std::ifstream file("../../res/files/config.xml");
	std::stringstream buffer;
	buffer << file.rdbuf();
	file.close();
	std::string content(buffer.str());
	doc.parse<0>(&content[0]);

	std::pair<int, int> coords;
	std::string nombreAttr;
	std::string nombreCoord;
	rapidxml::xml_node<> *pRoot = doc.first_node();
	rapidxml::xml_attribute<> *iAttr;
	rapidxml::xml_attribute<> *jAttr;
	rapidxml::xml_node<> *pNode = pRoot->first_node("Level");

	for (rapidxml::xml_attribute<> *iAttr1 = pNode->first_attribute(); iAttr1; iAttr1 = iAttr1->next_attribute())
	{
		nombreAttr = iAttr1->name();
		if (nombreAttr == "time")
		{
			tiempo = atoi(iAttr1->value());
		}
		if (nombreAttr == "lives")
		{
			cantidadVidas = atoi(iAttr1->value());
		}
	}
	for (rapidxml::xml_node<> *pNode1 = pNode->first_node("Fixed")->first_node("Wall"); pNode1; pNode1 = pNode1->next_sibling())
	{			
		for (rapidxml::xml_attribute<> *iAttr = pNode1->first_attribute(); iAttr; iAttr = iAttr->next_attribute())
		{
			nombreCoord = iAttr->name();
			if (nombreCoord == "i")
			{
				coords.first = atoi(iAttr->value());
			}
			else if (nombreCoord == "j")
			{
				FixBrick muriyo;
				coords.second = atoi(iAttr->value());
				muriyo.fixBrickTarget.x = muriyo.fixBrickTarget.y = 0;
				muriyo.fixBrickRect.w = muriyo.fixBrickRect.h = 48;
				muriyo.fixBrickTarget.w = muriyo.fixBrickTarget.h = 48;
				muriyo.fixBrickRect.y = (coords.first * 48) + 80 + 48;
				muriyo.fixBrickRect.x = (coords.second * 48) + 48; 
				MurosFijos.push_back(muriyo);
			}

		}
	}
	for (rapidxml::xml_node<> *pNode1 = pNode->first_node("Destructible")->first_node("Wall"); pNode1; pNode1 = pNode1->next_sibling())
	{
		for (rapidxml::xml_attribute<> *iAttr = pNode1->first_attribute(); iAttr; iAttr = iAttr->next_attribute())
		{
			nombreCoord = iAttr->name();
			if (nombreCoord == "i")
			{
				coords.first = atoi(iAttr->value());
			}
			else if (nombreCoord == "j")
			{
				DestructibleBrick muriyo;
				coords.second = atoi(iAttr->value());
				muriyo.destructibleBrickTarget.x = 48;
				muriyo.destructibleBrickTarget.y = 0;
				muriyo.destructibleBrickRect.w = muriyo.destructibleBrickRect.h = 48;
				muriyo.destructibleBrickTarget.w = muriyo.destructibleBrickTarget.h = 48;
				muriyo.destructibleBrickRect.y = (coords.first * 48) + 80 + 48;
				muriyo.destructibleBrickRect.x = (coords.second * 48) + 48; 
				MurosDestruibles.push_back(muriyo);
			}

		}
	}
}




void Map::ReadXML2()
{
	rapidxml::xml_document<> doc;
	std::ifstream file("../../res/files/config.xml");
	std::stringstream buffer;
	buffer << file.rdbuf();
	file.close();
	std::string content(buffer.str());
	doc.parse<0>(&content[0]);

	std::pair<int, int> coords;
	std::string nombreAttr;
	std::string nombreCoord;
	rapidxml::xml_node<> *pRoot = doc.first_node();
	rapidxml::xml_attribute<> *iAttr;
	rapidxml::xml_attribute<> *jAttr;
	rapidxml::xml_node<> *pNode = pRoot->last_node("Level");

	for (rapidxml::xml_attribute<> *iAttr1 = pNode->first_attribute(); iAttr1; iAttr1 = iAttr1->next_attribute())
	{
		nombreAttr = iAttr1->name();

		if (nombreAttr == "time")
		{
			tiempo = atoi(iAttr1->value());
		}
		if (nombreAttr == "lives")
		{
			cantidadVidas = atoi(iAttr1->value());
		}
	}
	for (rapidxml::xml_node<> *pNode1 = pNode->first_node("Fixed")->first_node("Wall"); pNode1; pNode1 = pNode1->next_sibling())
	{
		for (rapidxml::xml_attribute<> *iAttr = pNode1->first_attribute(); iAttr; iAttr = iAttr->next_attribute())
		{
			nombreCoord = iAttr->name();
			if (nombreCoord == "i")
			{
				coords.first = atoi(iAttr->value());
			}
			else if (nombreCoord == "j")
			{
				FixBrick muriyo;
				coords.second = atoi(iAttr->value());
				muriyo.fixBrickTarget.x = muriyo.fixBrickTarget.y = 0;
				muriyo.fixBrickRect.w = muriyo.fixBrickRect.h = 48;
				muriyo.fixBrickTarget.w = muriyo.fixBrickTarget.h = 48;
				muriyo.fixBrickRect.y = (coords.first * 48) + 80;
				muriyo.fixBrickRect.x = (coords.second * 48) + 48;
				MurosFijos.push_back(muriyo);
			}

		}
	}
	for (rapidxml::xml_node<> *pNode1 = pNode->first_node("Destructible")->first_node("Wall"); pNode1; pNode1 = pNode1->next_sibling())
	{
		for (rapidxml::xml_attribute<> *iAttr = pNode1->first_attribute(); iAttr; iAttr = iAttr->next_attribute())
		{
			nombreCoord = iAttr->name();
			if (nombreCoord == "i")
			{
				coords.first = atoi(iAttr->value());
			}
			else if (nombreCoord == "j")
			{
				DestructibleBrick muriyo;
				coords.second = atoi(iAttr->value());
				muriyo.destructibleBrickTarget.x = 48;
				muriyo.destructibleBrickTarget.y = 0;
				muriyo.destructibleBrickRect.w = muriyo.destructibleBrickRect.h = 48;
				muriyo.destructibleBrickTarget.w = muriyo.destructibleBrickTarget.h = 48;
				muriyo.destructibleBrickRect.y = (coords.first * 48) + 80;
				muriyo.destructibleBrickRect.x = (coords.second * 48) + 48;
				MurosDestruibles.push_back(muriyo);
			}

		}
	}
}

		


void Map::DrawMap1()
{					
	for (int i = 0; i < MurosFijos.size(); i++)
	{
		Renderer::Instance()->PushSprite(ITEMS_SPRITE, MurosFijos[i].fixBrickTarget, MurosFijos[i].fixBrickRect);
	}
}

void Map::DrawMap2()
{
	for (int i = 0; i < MurosFijos2.size(); i++)
	{
		Renderer::Instance()->PushSprite(ITEMS_SPRITE, MurosFijos2[i].fixBrickTarget, MurosFijos2[i].fixBrickRect);
	}
}

void Map::DrawBricks1()
{
	for (int i = 0; i < MurosDestruibles.size(); i++)
	{
		Renderer::Instance()->PushSprite(ITEMS_SPRITE, MurosDestruibles[i].destructibleBrickTarget, MurosDestruibles[i].destructibleBrickRect);
	}
}

void Map::DrawBricks2()
{
	for (int i = 0; i < MurosDestruibles2.size(); i++)
	{
		Renderer::Instance()->PushSprite(ITEMS_SPRITE, MurosDestruibles2[i].destructibleBrickTarget, MurosDestruibles2[i].destructibleBrickRect);
	}
}





Map::~Map()
{
}
