#include "FriendlyBaseView.h"
#include "Game.h"

FriendlyBaseView::FriendlyBaseView(const Base& base) : base(base) {
	if (!font.loadFromFile("assets/fonts/FiraSans-Bold.ttf")) {
		throw std::runtime_error("Failed to load font");
	}

	baseInfoText.setFont(font);
	baseInfoText.setString("Base: " + base.getName() + "\nType: Friendly\n");
	baseInfoText.setCharacterSize(24);
	baseInfoText.setFillColor(sf::Color::White);
	baseInfoText.setPosition(50, 50);
}

void FriendlyBaseView::handleInput(Game& game) {
	if (this->inputClock.getElapsedTime().asSeconds() > this->inputDeplay) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			this->emitEvent(GameEvent::ReturnToWorldMap);
		}
		this->inputClock.restart();
	}
}

void FriendlyBaseView::update() {

}

void FriendlyBaseView::render(Game& game) {
	sf::RenderWindow& window = game.getWindow();
	window.draw(baseInfoText);
}
