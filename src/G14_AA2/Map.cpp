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
	std::string nameAttr;
	std::string nameCoord;
	rapidxml::xml_node<> *pRoot = doc.first_node();
	rapidxml::xml_attribute<> *iAttr;
	rapidxml::xml_attribute<> *jAttr;
	rapidxml::xml_node<> *pNode = pRoot->first_node("Level");

	for (rapidxml::xml_attribute<> *iAttr1 = pNode->first_attribute(); iAttr1; iAttr1 = iAttr1->next_attribute())
	{
		nameAttr = iAttr1->name();
		if (nameAttr == "time")
		{
			time = atoi(iAttr1->value());
		}
		if (nameAttr == "lives")
		{
			livesNum = atoi(iAttr1->value());
		}
	}
	for (rapidxml::xml_node<> *pNode1 = pNode->first_node("Fixed")->first_node("Wall"); pNode1; pNode1 = pNode1->next_sibling())
	{			
		for (rapidxml::xml_attribute<> *iAttr = pNode1->first_attribute(); iAttr; iAttr = iAttr->next_attribute())
		{
			nameCoord = iAttr->name();
			if (nameCoord == "i")
			{
				coords.first = atoi(iAttr->value());
			}
			else if (nameCoord == "j")
			{
				FixBrick brickVec;
				coords.second = atoi(iAttr->value());
				brickVec.fixBrickTarget.x = brickVec.fixBrickTarget.y = 0;
				brickVec.fixBrickRect.w = brickVec.fixBrickRect.h = 48;
				brickVec.fixBrickTarget.w = brickVec.fixBrickTarget.h = 48;
				brickVec.fixBrickRect.y = (coords.first * 48) + 80 + 48;
				brickVec.fixBrickRect.x = (coords.second * 48) + 48;
				FixBricks.push_back(brickVec);
			}

		}
	}
	for (rapidxml::xml_node<> *pNode1 = pNode->first_node("Destructible")->first_node("Wall"); pNode1; pNode1 = pNode1->next_sibling())
	{
		for (rapidxml::xml_attribute<> *iAttr = pNode1->first_attribute(); iAttr; iAttr = iAttr->next_attribute())
		{
			nameCoord = iAttr->name();
			if (nameCoord == "i")
			{
				coords.first = atoi(iAttr->value());
			}
			else if (nameCoord == "j")
			{
				DestructibleBrick brickVec;
				coords.second = atoi(iAttr->value());
				brickVec.desBrickTarget.x = 48;
				brickVec.desBrickTarget.y = 0;
				brickVec.desBrickRect.w = brickVec.desBrickRect.h = 48;
				brickVec.desBrickTarget.w = brickVec.desBrickTarget.h = 48;
				brickVec.desBrickRect.y = (coords.first * 48) + 80 + 48;
				brickVec.desBrickRect.x = (coords.second * 48) + 48;
				DesBricks.push_back(brickVec);
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
	std::string nameAttr;
	std::string nameCoord;
	rapidxml::xml_node<> *pRoot = doc.first_node();
	rapidxml::xml_attribute<> *iAttr;
	rapidxml::xml_attribute<> *jAttr;
	rapidxml::xml_node<> *pNode = pRoot->last_node("Level");

	for (rapidxml::xml_attribute<> *iAttr1 = pNode->first_attribute(); iAttr1; iAttr1 = iAttr1->next_attribute())
	{
		nameAttr = iAttr1->name();

		if (nameAttr == "time")
		{
			time = atoi(iAttr1->value());
		}
		if (nameAttr == "lives")
		{
			livesNum = atoi(iAttr1->value());
		}
	}
	for (rapidxml::xml_node<> *pNode1 = pNode->first_node("Fixed")->first_node("Wall"); pNode1; pNode1 = pNode1->next_sibling())
	{
		for (rapidxml::xml_attribute<> *iAttr = pNode1->first_attribute(); iAttr; iAttr = iAttr->next_attribute())
		{
			nameCoord = iAttr->name();
			if (nameCoord == "i")
			{
				coords.first = atoi(iAttr->value());
			}
			else if (nameCoord == "j")
			{
				FixBrick brickVec;
				coords.second = atoi(iAttr->value());
				brickVec.fixBrickTarget.x = brickVec.fixBrickTarget.y = 0;
				brickVec.fixBrickRect.w = brickVec.fixBrickRect.h = 48;
				brickVec.fixBrickTarget.w = brickVec.fixBrickTarget.h = 48;
				brickVec.fixBrickRect.y = (coords.first * 48) + 80;
				brickVec.fixBrickRect.x = (coords.second * 48) + 48;
				FixBricks.push_back(brickVec);
			}

		}
	}
	for (rapidxml::xml_node<> *pNode1 = pNode->first_node("Destructible")->first_node("Wall"); pNode1; pNode1 = pNode1->next_sibling())
	{
		for (rapidxml::xml_attribute<> *iAttr = pNode1->first_attribute(); iAttr; iAttr = iAttr->next_attribute())
		{
			nameCoord = iAttr->name();
			if (nameCoord == "i")
			{
				coords.first = atoi(iAttr->value());
			}
			else if (nameCoord == "j")
			{
				DestructibleBrick brickVec;
				coords.second = atoi(iAttr->value());
				brickVec.desBrickTarget.x = 48;
				brickVec.desBrickTarget.y = 0;
				brickVec.desBrickRect.w = brickVec.desBrickRect.h = 48;
				brickVec.desBrickTarget.w = brickVec.desBrickTarget.h = 48;
				brickVec.desBrickRect.y = (coords.first * 48) + 80;
				brickVec.desBrickRect.x = (coords.second * 48) + 48;
				DesBricks.push_back(brickVec);
			}

		}
	}
}

		


void Map::DrawFixBricks()
{					
	for (int i = 0; i < FixBricks.size(); i++)
	{
		Renderer::Instance()->PushSprite(ITEMS_SPRITE, FixBricks[i].fixBrickTarget, FixBricks[i].fixBrickRect);
	}
}

void Map::DrawDesBricks()
{
	for (int i = 0; i < DesBricks.size(); i++)
	{
		Renderer::Instance()->PushSprite(ITEMS_SPRITE, DesBricks[i].desBrickTarget, DesBricks[i].desBrickRect);
	}
}





Map::~Map()
{
}
