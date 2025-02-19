#pragma once
#include <unordered_map>
#include <string>
#include <vector>
#include <SFML/System/Vector2.hpp>


class User {
private:
	int availableTroops;
	int availableDefenses;
	std::unordered_map<std::string, std::vector<sf::Vector2i>> baseDefenses;
	int queuedTroops;
	int queuedDefenses;

public:
	User();

	void addTroops(int count);
	void decrementTroops();
	int getAvailableTroops() const;

	void addDefenses(int count);
	void decrementDefenses();
	int getAvailableDefenses() const;

	void queueTroopTraining(int count);
	int getQueuedTroops() const;
	void completeTroopTraining();

	void queueDefenseBuilding(int count);
	int getQueuedDefenses() const;
	void completedDefenseBuilding();

	void removeBaseDefense(std::string baseID, sf::Vector2i position);
	std::vector<sf::Vector2i> getBaseDefenses(std::string baseID) const;
	void addBaseDefense(std::string baseID, sf::Vector2i);
};
