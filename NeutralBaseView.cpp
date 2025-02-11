#include "NeutralBaseView.h"
#include "Game.h"

NeutralBaseView::NeutralBaseView(const Base& base) : base(base) {
	if (!font.loadFromFile("assets/fonts/FiraSans-Bold.ttf")) {
		throw std::runtime_error("Failed to load font");
	}

	baseInfoText.setFont(font);
	baseInfoText.setString("Base: " + base.getName() + "\nType: Neutral\n");
	baseInfoText.setCharacterSize(24);
	baseInfoText.setFillColor(sf::Color::White);
	baseInfoText.setPosition(50, 50);
}

void NeutralBaseView::handleInput(Game& game) {
	if (this->inputClock.getElapsedTime().asSeconds() > this->inputDeplay) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			this->emitEvent(GameEvent::Return);
		}
		this->inputClock.restart();
	}
}

void NeutralBaseView::update() {

}

void NeutralBaseView::render(Game& game) {
	sf::RenderWindow& window = game.getWindow();
	window.draw(baseInfoText);
}
