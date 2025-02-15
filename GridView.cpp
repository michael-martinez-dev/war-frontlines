#include "GridView.h"
#include <iostream>


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

void GridView::resizeGrid(sf::RenderWindow& window) {
    sf::Vector2f windowSize = static_cast<sf::Vector2f>(window.getSize());

    float gridWidth = windowSize.x * 0.6f;
    float gridHeight = windowSize.y * 0.6f;
    float startX = (windowSize.x - gridWidth) / 2;
    float startY = (windowSize.y - gridHeight) / 2;

    cellSize = std::min(gridWidth / gridCols, gridHeight / gridRows);

    for (int i = 0; i < gridCells.size(); i++) {
        int row = i / gridCols;
        int col = i % gridCols;

        gridCells[i].setGridSquareSize(cellSize);
        gridCells[i].setGridSquarePosition(startX + col * cellSize, startY + row * cellSize);
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

    std::cout << "pressed: (" << x << ", " << y << ")\n";

    for (int i = 0; i < 8; i++) {
        int newX = x + surroundingGrids[i][0];
        int newY = y + surroundingGrids[i][1];
        std::cout << "NewX=" << newX << ", NewY=" << newY << "\n";

        // Ensure we don't go out of bounds
        if (newX >= 0 && newX < gridCols && newY >= 0 && newY < gridRows) {
            std::cout << "Added\n";
            bufferGridCells.push_back(sf::Vector2i(newX, newY));
        }
    }

    return bufferGridCells;
}

