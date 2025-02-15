#include "FriendlyBaseView.h"
#include "Game.h"
#include <iostream>

FriendlyBaseView::FriendlyBaseView(const Base& base, sf::RenderWindow& window) : BaseView(base, "Friendly") {
    setupGrid(window);
}

void FriendlyBaseView::render(Game& game) {
    sf::RenderWindow& window = game.getWindow();
    window.draw(baseInfoText);

    Base::BaseType type = base.getType();
    if (type != Base::BaseType::FriendlyHQ) {
        for (auto& cell : this->getGridCells()) {
            if (cell.getState() == GridCell::State::Buffer) {
                cell.setState(GridCell::State::Empty);
            }
        }
    }

    int i = 0;

    for (auto& cell : this->getGridCells()) {
        if (cell.getState() == GridCell::State::Defense) {
            std::vector<sf::Vector2i> bufferCells = getSurroundingGridCells(i % this->getNumRows(), i / this->getNumCols());
            
            for (sf::Vector2i& bufferIndex : bufferCells) {
                int bufferPos = bufferIndex.y * this->getNumCols() + bufferIndex.x;
                if (this->getGridCells()[bufferPos].getState() == GridCell::State::Empty) {
                    this->getGridCells()[bufferPos].setState(GridCell::State::Buffer);
                }
            }
        }
        i++;
    }

    for (auto& cell : this->getGridCells()) {
        window.draw(cell.getGridSquare());
    }
}

void FriendlyBaseView::handleInput(Game& game) {
    sf::RenderWindow& window = game.getWindow();
    sf::Event event;

    if (inputClock.getElapsedTime().asSeconds() > this->inputDelay) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            this->emitEvent(GameEvent::Return);
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            handleGridClick(window);
        }

        inputClock.restart();
    }

    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Resized) {
            resizeGrid(window);
        }
    }
}

void FriendlyBaseView::handleGridClick(sf::RenderWindow& window) {
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    std::vector<GridCell> gridCells = this->getGridCells();

    int i = 0;
        
    for (GridCell& cell : gridCells) {
        if (cell.getGridSquare()
            .getGlobalBounds()
            .contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y))) {

            if (cell.getState() == GridCell::State::Defense) {
                cell.setState(GridCell::State::Empty);
            }
            else if (cell.getState() == GridCell::State::Empty || cell.getState() == GridCell::State::Buffer) {
                cell.setState(GridCell::State::Defense);
            }

            this->setGridCells(gridCells);
   
                
            break;
        }
        i++;
    }
}
