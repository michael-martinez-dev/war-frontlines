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
        Base("HQ 1", {0.28f, 0.35f}, BaseType::FriendlyHQ),
        Base("Base 2", {0.38f, 0.62f}, BaseType::Friendly),
        Base("Base 3", {0.56f, 0.68f}, BaseType::Enemy),
        Base("HQ 2", {0.595f, 0.25f}, BaseType::EnemyHQ),
        Base("Base 4", {0.45f, 0.14f}, BaseType::Neutral)
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
