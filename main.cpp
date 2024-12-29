#include "Game.h"
#include "GameState.h"
#include "MainMenu.h"
#include <iostream>

int main() {
	try {
		Game *game = new Game();
		game->run();
	}
	catch (const std::exception& err) {
		std::cout << "Something went wrong!\n";
		std::cerr << "Error: " << err.what() << "\n";
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}