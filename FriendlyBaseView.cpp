#include "FriendlyBaseView.h"
#include "Game.h"

FriendlyBaseView::FriendlyBaseView(const Base& base) : BaseView(base, "Friendly") {}

void FriendlyBaseView::render(Game& game) {
    sf::RenderWindow& window = game.getWindow();
    setupGrid(window);
    window.draw(baseInfoText);

    Base::BaseType type = base.getType();
    if (type != Base::BaseType::FriendlyHQ) {
        for (auto& cell : this->getGridCells()) {
            window.draw(cell.getGridSquare());
        }
    }
}

void FriendlyBaseView::handleInput(Game& game) {
    sf::RenderWindow& window = game.getWindow();
    sf::Event event;
    if (inputClock.getElapsedTime().asSeconds() > this->inputDelay) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            this->emitEvent(GameEvent::Return);
        }
        inputClock.restart();
    }
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::MouseButtonPressed) {
            handleGridClick(window, event);
        }
    }
}

void FriendlyBaseView::handleGridClick(sf::RenderWindow& window, sf::Event event) {
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    std::vector<GridCell> gridCells = this->getGridCells();

    if (event.mouseButton.button == sf::Mouse::Left) {
        int i = 0;
        
        for (GridCell& cell : gridCells) {
            if (cell.getGridSquare()
                .getGlobalBounds()
                .contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y))) {

                if (cell.getState() == GridCell::State::Troop) {
                    cell.setState(GridCell::State::Empty);
                }
                else if (cell.getState() == GridCell::State::Empty) {
                    cell.setState(GridCell::State::Troop);

                    std::vector<sf::Vector2i> bufferCells = this->getSurroundingGridCells(
                        i % this->getNumRows(), i / this->getNumCols());

                    for (sf::Vector2i& cellIndex : bufferCells) {
                        gridCells[cellIndex.x * this->getNumCols() + cellIndex.y].setState(GridCell::State::Buffer);
                    }
                }
                this->setGridCells(gridCells);
                break;
            }
            i++;
        }
    }
}
