#pragma once
#include <unordered_map>
#include <vector>
#include <string>
#include <SFML/System/Vector2.hpp>


class EnemyUser {
private:
	std::unordered_map<std::string, std::vector<sf::Vector2i>> enemyBaseDefenses;

public:
    void generateBaseDefenses(const std::string& baseID, int difficulty);
	const std::vector<sf::Vector2i>& getEnemyBaseDefenses(std::string baseID) const;
};
