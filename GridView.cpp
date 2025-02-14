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

std::vector<GridCell> GridView::getGridCells() {
    return this->gridCells;
}

void GridView::setGridCells(std::vector<GridCell> new_grid_cells) {
    this->gridCells = new_grid_cells;
}

std::vector<sf::Vector2i> GridView::getSurroundingGridCells(int x, int y) {
    std::vector<sf::Vector2i> bufferGridCells;
    bool surroundingGridIndexes[8] = { 1,1,1,1,1,1,1,1 };

    if (y == 0) {
        surroundingGridIndexes[0] = 0;
        surroundingGridIndexes[1] = 0;
        surroundingGridIndexes[2] = 0;
    }
    else if (y == this->gridRows) {
        surroundingGridIndexes[5] = 0;
        surroundingGridIndexes[6] = 0;
        surroundingGridIndexes[7] = 0;
    }

    if (x == 0) {
        surroundingGridIndexes[0] = 0;
        surroundingGridIndexes[3] = 0;
        surroundingGridIndexes[5] = 0;
    }
    else if (x == this->gridCols) {
        surroundingGridIndexes[2] = 0;
        surroundingGridIndexes[4] = 0;
        surroundingGridIndexes[7] = 0;
    }

    for (int i = 0; i < 8; i++) {
        if (surroundingGridIndexes[i]) {
            bufferGridCells.push_back(sf::Vector2i(x +  this->surroundingGrids[i][0], y + this->surroundingGrids[i][1]));
        }
    }

    return bufferGridCells;
}
