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
        for (auto& cell : gridCells) {
            window.draw(cell.getGridSquare());
        }
    }
}
