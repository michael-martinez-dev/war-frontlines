#include "User.h"

User::User() : availableTroops(10), availableDefenses(5), queuedTroops(0), queuedDefenses(0), baseDefenses() {

}

void User::addTroops(int count) {
	this->availableTroops += count;
}

void User::decrementTroops() {
	if (this->availableTroops > 0) {
		this->availableTroops--;
	}
}

int User::getAvailableTroops() const {
	return this->availableTroops;
}

void User::addDefenses(int count) {
	this->availableDefenses += count;
}

void User::decrementDefenses() {
	if (this->availableDefenses > 0) {
		this->availableDefenses--;
	}
}

int User::getAvailableDefenses() const {
	return this->availableDefenses;
}

void User::queueTroopTraining(int count) {
}

int User::getQueuedTroops() const {
	return this->queuedTroops;
}

void User::completeTroopTraining() {

}

void User::queueDefenseBuilding(int count) {

}

int User::getQueuedDefenses() const {
	return this->queuedDefenses;
}

void User::completedDefenseBuilding() {

}

void User::removeBaseDefense(std::string baseID, sf::Vector2i position) {
	auto& defenses = baseDefenses[baseID];
	defenses.erase(std::remove(defenses.begin(), defenses.end(), position), defenses.end());
}

std::vector<sf::Vector2i> User::getBaseDefenses(std::string baseID) const {  
   try {  
       return this->baseDefenses.at(baseID);  
   }  
   catch (std::exception e) {  
       return std::vector<sf::Vector2i>();  
   }  
}

void User::addBaseDefense(std::string baseID, sf::Vector2i position) {
	baseDefenses[baseID].push_back(position);
}

