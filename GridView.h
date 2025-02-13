#pragma once
#include "GridCell.h"
#include <SFML/Graphics.hpp>


class GridView
{
protected:
	// Grid
	std::vector<GridCell> gridCells;
	const int gridRows = 20;
	const int gridCols = 20;
	float cellSize;

public:
	void setupGrid(sf::RenderWindow& window);
};

