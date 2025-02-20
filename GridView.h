#pragma once
#include "GridCell.h"
#include "Game.h"
#include <SFML/Graphics.hpp>
#include <vector>

class GridView
{
private:
	// Grid
	std::vector<GridCell> gridCells;
	const int gridRows = 15;
	const int gridCols = 15;
	float cellSize = 1.0;
	const int surroundingGrids[8][2] = {
	{-1,-1},
	{-1,0},
	{-1,1},
	{0,-1},
	{0,1},
	{1,-1},
	{1,0},
	{1,1},
}; // Change to const

public:
	void setupGrid(sf::RenderWindow& window);
	void resizeGrid(sf::RenderWindow& window);
	std::vector<GridCell>& getGridCells();
	void setGridCells(std::vector<GridCell> new_grid_cells);
	virtual void handleGridClick(Game& game) = 0;
	std::vector<sf::Vector2i> getSurroundingGridCells(int x, int y);
	int getNumRows() { return gridRows; }
	int getNumCols() { return gridCols; }
};

