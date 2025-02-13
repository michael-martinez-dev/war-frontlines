#include "BaseView.h"
#include "Game.h"


BaseView::BaseView(const Base& base, const std::string& type) : base(base) {
    if (!font.loadFromFile("assets/fonts/FiraSans-Bold.ttf")) {
        throw std::runtime_error("Failed to load font");
    }

    setupBaseInfoText(type);

    baseGridOutline.setFillColor(sf::Color::Black);
    baseGridOutline.setOutlineColor(sf::Color::White);
    baseGridOutline.setSize(sf::Vector2f(100, 100));
    baseGridOutline.setPosition(sf::Vector2f(500, 500));
}

void BaseView::setupBaseInfoText(const std::string& type) {
    baseInfoText.setFont(font);
    baseInfoText.setString("Base: " + base.getName() + "\nType: " + type);
    baseInfoText.setCharacterSize(24);
    baseInfoText.setFillColor(sf::Color::White);
    baseInfoText.setPosition(50, 50);
}

void BaseView::handleInput(Game& game) {
    if (inputClock.getElapsedTime().asSeconds() > this->inputDelay) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            this->emitEvent(GameEvent::Return);
        }
        inputClock.restart();
    }
}

void BaseView::update() {
    // Placeholder for animations or UI changes
}

void BaseView::render(Game& game) {
    sf::RenderWindow& window = game.getWindow();
    window.draw(baseInfoText);
}

