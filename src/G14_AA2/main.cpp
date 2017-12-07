#include <SDL.h>
#include "Game.h"


Game *game = nullptr;

int main(int argc, char *argv[]) 
{
	game = new Game();
	
	return 0;
}