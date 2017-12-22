#include "Map.h"



Map::Map()
{
	rapidxml::xml_document<> doc;
	std::ifstream file("../../res/files/config.xml");
	std::stringstream buffer;
	buffer << file.rdbuf();
	file.close();
	std::string content(buffer.str());
	doc.parse<0>(&content[0]);

	int valorI;
	int valorJ;
	rapidxml::xml_node<> *pRoot = doc.first_node();
	rapidxml::xml_attribute<> *iAttr;
	rapidxml::xml_attribute<> *jAttr;

	for (rapidxml::xml_node<> *pNode = pRoot->first_node("Level"); pNode; pNode = pNode->next_sibling())
	{
		std::cout << pNode->name() << ':' << '\n';
		//atributos del node book
		/*for (rapidxml::xml_attribute<> *pAttr = pNode->first_attribute(); pAttr; pAttr = pAttr->next_attribute())
		{
			std::cout << '-' << pAttr->name() << '-' << pAttr->value() << '\n';
		};*/
		for (rapidxml::xml_node<> *pNode1 = pNode->first_node("Fixed"); pNode1; pNode1 = pNode1->next_sibling())
		{
			for (rapidxml::xml_node<> *pNode2 = pNode1->first_node("Wall"); pNode2; pNode2 = pNode2->next_sibling())
			{
					for (rapidxml::xml_attribute<> *iAttr = pNode2->first_attribute(); iAttr; iAttr = iAttr->next_attribute())
					{
						std::cout << iAttr->value() << "\n";
						//valorI =
					}
				
				/*valorI = atoi(pNode2->first_node("i")->value());
				valorJ = atoi(pNode2->first_node("j")->value());*/
				
				/*std::cout << "i: " << valorI << "\n";
				std::cout << "j: " << valorJ << "\n";*/
			}
		}
		std::cout << "\n";
	}

	/*for (rapidxml::xml_node<> *pNode = pRoot->first_node("Fixed"); pNode; pNode = pNode->next_sibling())
	{
		for (rapidxml::xml_node<> *pNode2 = pRoot->first_node("Wall"); pNode2; pNode2 = pNode2->next_sibling())
		{

			valorI = atoi(pNode2->first_node("i")->value());
			valorJ = atoi(pNode2->first_node("j")->value());
			std::cout << "i : " << iAttr->value() << std::endl;
			std::cout << "j : " << jAttr->value() << std::endl;
		}
	}*/

	/*int posicionX = 96;
	int posicionY = 176;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			ladrillos[i][j].posX = posicionX;
			ladrillos[i][j].posY = posicionY;
			TodosLosMuros.push_back({ posicionX, posicionY, 48, 48 });
			// Para detectar colisiones cogemos el player y detectamos si se mueve en alguno de los bricks del vector con un iterador
			posicionX += 96;
		}
		posicionX = 96;
		posicionY += 96;
	}

	int posX = 96;
	int posY = 80;
	for (int i = 0; i < 155; i++)
	{
		if (craps[i] == 1)
		{
			TodosLosMuros.push_back({ posX, posY, 48, 48 });
		}
		else
		{
			posX += 48;
		}
		if (i % 14 == 0)
		{
			posY += 48;
			posX = 0;
		}
	}*/
}

void Map::DrawMap()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			ladrillu.printBrick(ladrillos[i][j].posX, ladrillos[i][j].posY);
		}
	}
}

void Map::DrawBricks()
{
	int posX = 96;
	int posY = 80;
	for (int i = 0; i < 155; i++)
	{
		if (craps[i] == 1)
		{
			ladrillu.printDestructible(posX, posY);
			posX += 48;
		}
		else
		{
			posX += 48;
		}
		if (i % 14 == 0)
		{
			posY += 48;
			posX = 0;
		}
	}
}





Map::~Map()
{
}
