#include <SDL.h>
#include "Game.h"



int main(int argc, char *argv[]) 
{
	srand(time(NULL));
	Game game;
	game.GameLoop();
	
	return 0;
}