#include "MainMenu.h"
#include <iostream>


MainMenu::MainMenu() {
	if (!font.loadFromFile("assets/fonts/FiraSans-Bold.ttf")) {
		throw std::runtime_error("Failed to load font");
	}
}

void MainMenu::handleInput(Game& game) {

	if (this->inputClock.getElapsedTime().asSeconds() > this->inputDeplay) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			this->selectedOption = (this->selectedOption + 1) % options.size();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			this->selectedOption = (this->selectedOption - 1) % options.size();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
			if (this->selectedOption == 0) {
				this->emitEvent(GameEvent::StartGame);
			}
			else if (this->selectedOption == 1) {
				this->emitEvent(GameEvent::ExitGame);
			}
		}
		this->inputClock.restart();
	}
}

void MainMenu::update() {}

void MainMenu::render(Game& game) {
	sf::RenderWindow& window = game.getWindow();
	float windowWidth = window.getView().getSize().x;
	float windowHeight = window.getView().getSize().y;

	for (size_t i = 0; i < options.size(); ++i) {
		sf::Text text(options[i], this->font, 36);

		text.setPosition(
			windowWidth / 2 - text.getGlobalBounds().width / 2,
			windowHeight / 2 + (i - options.size() / 2.0f) * 50
		);

		text.setFillColor(i == selectedOption ? sf::Color::Red : sf::Color::White);

		window.draw(text);
	}
}
