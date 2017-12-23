#include "Ranking.h"

Ranking::Ranking()
{
	returnMenuRect = { 20, 650, medidaTextMenu.x, medidaTextMenu.y };
	returnMenu = false;

	struct playerData
	{
		std::string name;
		int score;
	};
	std::string auxname;
	int auxscore = 0;
	playerData aux;
	std::vector<playerData> Highscores;
	std::vector<playerData> ReadScores;
	playerData Player1{ "Satan", 10 };
	playerData Player2{ "Bulma", 20 };
	playerData Player3{ "Roshi", 30 };
	playerData Player4{ "Piccolo", 40 };
	playerData Player5{ "Goten", 50 };
	playerData Player6{ "Trunks", 70 };
	playerData Player7{ "Gohan", 60 };
	playerData Player8{ "Freezer", 80 };
	playerData Player9{ "Vegeta", 90 };
	playerData Player10{ "Goku", 100 };

	Highscores.push_back(Player1);
	Highscores.push_back(Player2);
	Highscores.push_back(Player3);
	Highscores.push_back(Player4);
	Highscores.push_back(Player5);
	Highscores.push_back(Player6);
	Highscores.push_back(Player7);
	Highscores.push_back(Player8);
	Highscores.push_back(Player9);
	Highscores.push_back(Player10);

	std::ofstream fsalida("../../res/files/ranking.bin", std::ios_base::binary);
	std::ifstream fentrada("../../res/files/ranking.bin", std::ios_base::binary);
	if (fsalida.good())
	{		

		for (int i = 0; i < 10; i++)
		{
			fsalida.write(Highscores[i].name.c_str(), Highscores[i].name.size()); // write string to binary file
			fsalida.write("\0", sizeof(char)); // null end string for easier reading
			fsalida.write(reinterpret_cast<char*>(&Highscores[i].score), sizeof(Highscores[i].score)); // write int to binary file
		}
		fsalida.close();
	}
	
	if (fentrada.good())
	{		
		for (int i = 0; fentrada.eof() != true; i++)
		{
			std::getline(fentrada, auxname, '\0'); // get player name (remember we null ternimated in binary)
			fentrada.read(reinterpret_cast<char *>(&auxscore), sizeof(auxscore));			// read int bytes
			aux = { auxname, auxscore };
			ReadScores.push_back(aux);			
		}
	}
	ReadScores.erase(ReadScores.end()-1);
	//std::sort(ReadScores.begin(), ReadScores.end());
	for (int i = 0; i < ReadScores.size(); i++)
	{
		std::cout << "Player " << i+1 << " name: " << ReadScores[i].name << std::endl;
		std::cout << "Player " << i+1 << " score: " << ReadScores[i].score << std::endl;
	}
}

Ranking::~Ranking()
{
}

void Ranking::Update()
{
}

void Ranking::Draw()
{
	Renderer::Instance()->Clear();
	Renderer::Instance()->PushImage(TEXT_RETURNMENU, returnMenuRect);
	Renderer::Instance()->Render();
}

void Ranking::HandleEvents()
{
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_MOUSEMOTION:	
			if (event.motion.x >= 20 && event.motion.x <= (medidaTextMenu.x) + 20 && event.motion.y >= 650 && event.motion.y <= medidaTextMenu.y + 650)
			{
				std::cout << "return";
				returnMenu = true;
			}
			else
			{
				returnMenu = false;
			}

			break;
		case SDL_MOUSEBUTTONDOWN:
			if (returnMenu == true)
			{
				state = GameState::GOTO;
			}
		default:;
		}
	}
}
