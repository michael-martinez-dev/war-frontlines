#include "Game.h"
#include <iostream>

int main() {
	try {
		User user;
		Game game;
		game.setUser(user);
		game.run();
	}
	catch (const std::exception& err) {
		std::cout << "Something went wrong!\n";
		std::cerr << "Error: " << err.what() << "\n";
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}