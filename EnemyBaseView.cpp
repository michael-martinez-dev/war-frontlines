#include "EnemyBaseView.h"
#include "Game.h"

EnemyBaseView::EnemyBaseView(EnemyUser& eUser, const Base& base, sf::RenderWindow& window) : BaseView(base, "Enemy") {
    setupGrid(window);

    eUser.generateBaseDefenses(base.getName(), 5);

    for (auto& cellPosition : eUser.getEnemyBaseDefenses(this->base.getName())) {
        int defensePosition = cellPosition.x * this->getNumCols() + cellPosition.y;
        this->getGridCells()[defensePosition].setState(GridCell::State::Defense);
    }
}

void EnemyBaseView::render(Game& game) {
    sf::RenderWindow& window = game.getWindow();
    window.draw(baseInfoText);
   

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

void EnemyBaseView::handleInput(Game& game) {
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

void EnemyBaseView::handleGridClick(Game& game) {
    sf::Vector2i mousePosition = sf::Mouse::getPosition(game.getWindow());
    std::vector<GridCell> gridCells = this->getGridCells();

    int i = 0;

    for (GridCell& cell : gridCells) {
        if (cell.getGridSquare()
            .getGlobalBounds()
            .contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y))) {

            if (cell.getState() == GridCell::State::Troop) {
                cell.setState(GridCell::State::Empty);
                game.getUser().addTroops(1);
            }
            else if (cell.getState() == GridCell::State::Empty && game.getUser().getAvailableTroops() > 0) {
                cell.setState(GridCell::State::Troop);
                game.getUser().decrementTroops();
            }

            this->setGridCells(gridCells);


            break;
        }
        i++;
    }
}
