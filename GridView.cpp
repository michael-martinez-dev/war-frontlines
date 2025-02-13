#include "GridView.h"


void GridView::setupGrid(sf::RenderWindow& window) {
    sf::Vector2f windowSize = static_cast<sf::Vector2f>(window.getSize());

    float gridWidth = windowSize.x * 0.6f;
    float gridHeight = windowSize.y * 0.6f;
    float startX = (windowSize.x - gridWidth) / 2;
    float startY = (windowSize.y - gridHeight) / 2;

    cellSize = std::min(gridWidth / gridCols, gridHeight / gridRows);

    gridCells.clear();

    for (int row = 0; row < gridRows; row++) {
        for (int col = 0; col < gridCols; col++) {
            GridCell cell(cellSize, GridCell::State::Empty);
            cell.setGridSquarePosition(startX + col * cellSize, startY + row * cellSize);
            gridCells.push_back(cell);
        }
    }
}

