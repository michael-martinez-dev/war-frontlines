#include "Base.h"

Base::Base(std::string name, sf::Vector2f position, BaseType type) {
    this->name = name;
    this->position = position;
    this->type = type;
}

std::string Base::getName() const {
	return this->name;
}

sf::Vector2f Base::getPosition() const {
	return this->position;
}

Base::BaseType Base::getType() const {
	return this->type;
}

std::vector<Base> Base::getExampleBases() {
    return std::vector<Base> {
        Base("Base 1", {0.07f, 0.14f}, BaseType::Neutral),
        Base("Friendly HQ", {0.28f, 0.35f}, BaseType::FriendlyHQ),
        Base("Friendly A", {0.38f, 0.62f}, BaseType::Friendly),
        Base("Enemy A", {0.56f, 0.68f}, BaseType::Enemy),
        Base("Enemy HQ", {0.6f, 0.25f}, BaseType::EnemyHQ),
    };
}

void Base::setName(std::string name) {
    this->name = name;
}

void Base::setPosition(sf::Vector2f position) {
    this->position = position;
}

void Base::setPosition(float x, float y) {
    this->position = sf::Vector2f(x, y);
}

void Base::setType(Base::BaseType type) {
    this->type = type;
}
