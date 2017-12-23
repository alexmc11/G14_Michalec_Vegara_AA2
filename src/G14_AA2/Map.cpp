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

	int aux = 0;
	int aux2 = 0;
	int valorI = 0;
	int valorJ = 0;
	rapidxml::xml_node<> *pRoot = doc.first_node();
	rapidxml::xml_attribute<> *iAttr;
	rapidxml::xml_attribute<> *jAttr;

	for (rapidxml::xml_node<> *pNode = pRoot->first_node("Level"); pNode; pNode = pNode->next_sibling())
	{
		std::cout << pNode->name() << ':' << '\n';
		for (rapidxml::xml_attribute<> *iAttr1 = pNode->first_attribute(); iAttr1; iAttr1 = iAttr1->next_attribute())
		{
			aux2++;
			if (aux2 == 1)
			{
				levelID = atoi(iAttr1->value());
				std::cout << "Level ID: " << levelID << "\n";
			}
			else if (aux2 == 2)
			{
				tiempo = atoi(iAttr1->value());
				std::cout << "Tiempo: " << tiempo << "\n";
			}
			else if (aux2 == 3)
			{
				cantidadVidas = atoi(iAttr1->value());
				std::cout << "Vidas: " << cantidadVidas << "\n";
			}
			else if (aux2 == 4)
			{
				std::cout << "Paco: " << iAttr1->value() << "\n";
			}
		}
		for (rapidxml::xml_node<> *pNode1 = pNode->first_node("Fixed"); pNode1; pNode1 = pNode1->next_sibling())
		{
			
			for (rapidxml::xml_node<> *pNode2 = pNode1->first_node("Wall"); pNode2; pNode2 = pNode2->next_sibling())
			{
				aux = 0;
				for (rapidxml::xml_attribute<> *iAttr = pNode2->first_attribute(); iAttr; iAttr = iAttr->next_attribute())
				{
					aux++;
					if (aux == 1)
					{
						valorI = atoi(iAttr->value());
					}
					else if (aux == 2)
					{
						valorJ = atoi(iAttr->value());
						
						if(MurosFijos.size() < 30)
						{
							FixBrick muriyo;
							muriyo.fixBrickTarget.x = muriyo.fixBrickTarget.y = 0;
							muriyo.fixBrickRect.w = muriyo.fixBrickRect.h = 48;
							muriyo.fixBrickTarget.w = muriyo.fixBrickTarget.h = 48;
							muriyo.fixBrickRect.y = (valorI * 48) + 80 + 48;
							muriyo.fixBrickRect.x = (valorJ * 48) + 48; //
							MurosFijos.push_back(muriyo);
						}
						else if(MurosFijos2.size() < 16)
						{
							FixBrick muriyo2;
							muriyo2.fixBrickTarget.x = muriyo2.fixBrickTarget.y = 0;
							muriyo2.fixBrickRect.w = muriyo2.fixBrickRect.h = 48;
							muriyo2.fixBrickTarget.w = muriyo2.fixBrickTarget.h = 48;
							muriyo2.fixBrickRect.y = (valorI * 48) + 80 + 48;
							muriyo2.fixBrickRect.x = (valorJ * 48) + 48; //
							MurosFijos2.push_back(muriyo2);
						}
						aux = 0;
					}
				}
			}
		}
		for (rapidxml::xml_node<> *pNode1 = pNode->first_node("Destructible"); pNode1; pNode1 = pNode1->next_sibling())
		{

			for (rapidxml::xml_node<> *pNode2 = pNode1->first_node("Wall"); pNode2; pNode2 = pNode2->next_sibling())
			{
				aux = 0;
				for (rapidxml::xml_attribute<> *iAttr = pNode2->first_attribute(); iAttr; iAttr = iAttr->next_attribute())
				{
					aux++;
					if (aux == 1)
					{
						valorI = atoi(iAttr->value());
					}
					else if (aux == 2)
					{
						valorJ = atoi(iAttr->value());

						if (MurosDestruibles.size() < 33)
						{
							DestructibleBrick muriyo;
							muriyo.destructibleBrickTarget.x = 48;
							muriyo.destructibleBrickTarget.y = 0;
							muriyo.destructibleBrickRect.w = muriyo.destructibleBrickRect.h = 48;
							muriyo.destructibleBrickTarget.w = muriyo.destructibleBrickTarget.h = 48;
							muriyo.destructibleBrickRect.y = (valorI * 48) + 80 + 48;
							muriyo.destructibleBrickRect.x = (valorJ * 48) + 48; //
							MurosDestruibles.push_back(muriyo);
						}
						aux = 0;
					}
				}
			}
		}
		std::cout << "\n";
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
