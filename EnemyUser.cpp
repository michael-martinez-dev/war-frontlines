#include "EnemyUser.h"
#include <string>

void EnemyUser::generateBaseDefenses(const std::string& baseID, int difficulty) {
	int numDefenses = difficulty * 3 + (rand() % 5);

	for (int i = 0; i < numDefenses; i++) {
		int x = rand() % 10;
		int y = rand() % 10;
		this->enemyBaseDefenses[baseID].push_back(sf::Vector2i(x, y));
	}
}

const std::vector<sf::Vector2i>& EnemyUser::getEnemyBaseDefenses(std::string baseID) const {
	try {
		return this->enemyBaseDefenses.at(baseID);
	}
	catch (std::exception e) {
		return std::vector<sf::Vector2i>();
	}
}