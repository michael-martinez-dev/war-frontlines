#include "FriendlyBaseView.h"
#include "Game.h"
#include <iostream>

FriendlyBaseView::FriendlyBaseView(const User& user, const Base& base, sf::RenderWindow& window) : BaseView(base, "Friendly") {
    setupGrid(window);

    for (auto& cellPosition : user.getBaseDefenses(this->base.getName())) {
        int defensePosition = cellPosition.x * this->getNumCols() + cellPosition.y;
        this->getGridCells()[defensePosition].setState(GridCell::State::Defense);
    }
}

void FriendlyBaseView::render(Game& game) {
    sf::RenderWindow& window = game.getWindow();
    User& user = game.getUser();
    window.draw(baseInfoText);


    for (auto& cell : this->getGridCells()) {
        if (cell.getState() == GridCell::State::Buffer) {
            cell.setState(GridCell::State::Empty);
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

    static bool needsResizeUpdate = false;

    if (inputClock.getElapsedTime().asSeconds() > this->inputDelay) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            this->emitEvent(GameEvent::Return);
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            handleGridClick(game);
        }

        inputClock.restart();
    }

    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Resized) {
            needsResizeUpdate = true;
        }

    }
    if (needsResizeUpdate) {
        resizeGrid(window);
        needsResizeUpdate = false;
    }
}

void FriendlyBaseView::handleGridClick(Game& game) {
    sf::Vector2i mousePosition = sf::Mouse::getPosition(game.getWindow());
    std::vector<GridCell> gridCells = this->getGridCells();

    int i = 0;
        
    for (GridCell& cell : gridCells) {
        if (cell.getGridSquare()
            .getGlobalBounds()
            .contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y))) {

            if (cell.getState() == GridCell::State::Defense) {
                cell.setState(GridCell::State::Empty);
                game.getUser().removeBaseDefense(this->base.getName(), sf::Vector2i(i / this->getNumCols(), i % this->getNumCols()));
                game.getUser().addDefenses(1);
            }
            else if ((cell.getState() == GridCell::State::Empty || cell.getState() == GridCell::State::Buffer) && game.getUser().getAvailableDefenses() > 0) {
                cell.setState(GridCell::State::Defense);
                game.getUser().addBaseDefense(this->base.getName(), sf::Vector2i(i / this->getNumCols(), i % this->getNumCols()));
                game.getUser().decrementDefenses();
            }

            this->setGridCells(gridCells);
  
                
            break;
        }
        i++;
    }
}
