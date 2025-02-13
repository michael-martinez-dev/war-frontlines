#pragma once
#include <SFML/Graphics.hpp>
class GridCell
{
public:
	enum class State {
		Troop,
		Defense,
		Empty,
		Buffer,
	};

	GridCell(float size, GridCell::State state);
	sf::RectangleShape& getGridSquare();
	State getState() const;
	void setGridSquareSize(float size);
	void setGridSquarePosition(float x, float y);
	void setState(State new_state);

private:
	State state;
	sf::RectangleShape gridSquare;
};

