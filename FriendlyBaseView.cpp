#include "FriendlyBaseView.h"
#include "Game.h"

FriendlyBaseView::FriendlyBaseView(const Base& base) : BaseView(base, "Friendly") {}

void FriendlyBaseView::render(Game& game) {
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
