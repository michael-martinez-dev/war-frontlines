#include "EnemyBaseView.h"
#include "Game.h"

EnemyBaseView::EnemyBaseView(const Base& base) : BaseView(base, "Enemy") {

}

void EnemyBaseView::render(Game& game) {
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

void EnemyBaseView::handleGridClick(sf::RenderWindow& window, sf::Event event) {

}
