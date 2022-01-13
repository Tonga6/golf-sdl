#include "SDL.h"
#include "stdio.h"
#include "Game.h"

Game *game = nullptr;
int main(int argc, char* argv[]) {

	game = new Game();
	game->init("Golf", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600);

	//loop while game is running
	while (game->checkRunning()) {
		game->handleEvents();
		game->update();
		game->render();
	}

	//else clean up before quitting
	game->clean();
	return 0;
}

