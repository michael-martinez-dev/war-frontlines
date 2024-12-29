#include "WorldMap.h"
#include <iostream>
#include <math.h>


WorldMap::WorldMap() {
	if (!this->mapTexture.loadFromFile("assets/images/earth_background.png")) {
		throw std::runtime_error("Failed to load world map image");
	}
	this->mapSprite.setTexture(this->mapTexture);

	if (!font.loadFromFile("assets/fonts/FiraSans-Bold.ttf")) {
		throw std::runtime_error("Failed to load font.");
	}

	sf::Vector2u textureSize = mapTexture.getSize();
	sf::Vector2u windowSize(1440, 720);

	float scaleX = static_cast<float>(windowSize.x) / textureSize.x;
	float scaleY = static_cast<float>(windowSize.y) / textureSize.y;
	this->mapSprite.setScale(scaleX, scaleY);
}

int WorldMap::getBaseClicked(sf::RenderWindow& window) {
	sf::Vector2i positionClicked = sf::Mouse::getPosition(window);
	float windowX = window.getView().getSize().x;
	float windowY = window.getView().getSize().y;

	sf::Vector2f mapSize = static_cast<sf::Vector2f>(this->mapTexture.getSize());
	float scaleX = static_cast<float>(windowX) / mapSize.x;
	float ScaleY = static_cast<float>(windowY) / mapSize.y;

	sf::Vector2f mapScale = this->mapSprite.getScale();

	for (size_t i = 0; i < this->bases.size(); i++) {
		int xDiff = (int)(this->bases[i].getPosition().x * mapSize.x * mapScale.x) - positionClicked.x;
		int yDiff = (int)(this->bases[i].getPosition().y * mapSize.y * mapScale.y) - positionClicked.y;

		if ((std::abs(xDiff) < 10) && (std::abs(yDiff) < 10)) {
			return i;
		}
	}

	return -1;
}

void WorldMap::handleInput(Game& game) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
		this->emitEvent(GameEvent::ReturnToMainMenu);
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		int baseClicked = this->getBaseClicked(game.getWindow());
		if (baseClicked != -1) {
			this->baseSelected = baseClicked;
		}
	}
	if (this->inputClock.getElapsedTime().asSeconds() > this->inputDeplay) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab)) {
			this->baseSelected = ++this->baseSelected % this->bases.size();
		}
		this->inputClock.restart();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			this->emitEvent(GameEvent::GoToBase);
		}
	}
}

void WorldMap::update() {

}

sf::Color WorldMap::getBaseColor(Base::BaseType baseType) {
	if (baseType == Base::BaseType::Neutral) {
		return sf::Color::Yellow;
	}
	else if (baseType == Base::BaseType::Friendly) {
		return sf::Color::Green;
	}
	else if (baseType == Base::BaseType::Enemy) {
		return sf::Color::Red;
	}
	else if (baseType == Base::BaseType::FriendlyHQ) {
		return sf::Color::Blue;
	}
	else if (baseType == Base::BaseType::EnemyHQ) {
		return sf::Color::Magenta;
	}
}

void WorldMap::render(Game& game) {
	sf::RenderWindow& window = game.getWindow();
	float windowX = window.getView().getSize().x;
	float windowY = window.getView().getSize().y;

	sf::Vector2f mapSize = static_cast<sf::Vector2f>(this->mapTexture.getSize());
	float scaleX = static_cast<float>(windowX) / mapSize.x;
	float ScaleY = static_cast<float>(windowY) / mapSize.y;

	sf::Vector2f mapScale = this->mapSprite.getScale();

	this->mapSprite.setScale(scaleX, ScaleY);
	window.draw(this->mapSprite);

	int i = 0;
	for (Base& base : bases) {
		sf::Vector2f basePosition = {
			base.getPosition().x * mapSize.x * mapScale.x,
			base.getPosition().y * mapSize.y * mapScale.y
		};

		sf::CircleShape marker(10);
		marker.setPosition(basePosition.x, basePosition.y);
		marker.setOrigin(10, 10);
		marker.setFillColor(this->getBaseColor(base.getType()));
		if (i == baseSelected) {
			marker.setOutlineColor(sf::Color::White);
			marker.setOutlineThickness(5.0f);
		}
		window.draw(marker);

		sf::Text baseName(base.getName(), font, 20);
		baseName.setPosition(basePosition.x + 15, basePosition.y - 10);
		baseName.setFillColor(sf::Color::White);
		window.draw(baseName);
		i++;
	}
}

Base WorldMap::getSelectedBase() {
	return this->bases[this->baseSelected];
}
