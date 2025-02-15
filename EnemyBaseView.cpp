#include "EnemyBaseView.h"
#include "Game.h"

EnemyBaseView::EnemyBaseView(const Base& base, sf::RenderWindow& window) : BaseView(base, "Enemy") {
    setupGrid(window);
}

void EnemyBaseView::render(Game& game) {
    sf::RenderWindow& window = game.getWindow();
    window.draw(baseInfoText);

    Base::BaseType type = base.getType();
    if (type != Base::BaseType::FriendlyHQ) {
        for (auto& cell : this->getGridCells()) {
            window.draw(cell.getGridSquare());
        }
    }
}

void EnemyBaseView::handleInput(Game& game) {
    sf::RenderWindow& window = game.getWindow();
    sf::Event event;
    if (inputClock.getElapsedTime().asSeconds() > this->inputDelay) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            this->emitEvent(GameEvent::Return);
        }
        inputClock.restart();
    }
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Resized) {
            resizeGrid(window);
        }
        if (event.type == sf::Event::MouseButtonPressed) {
            handleGridClick(window, event);
        }
    }
}

void EnemyBaseView::handleGridClick(sf::RenderWindow& window, sf::Event event) {

}
