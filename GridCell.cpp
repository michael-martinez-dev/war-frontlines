#include "GridCell.h"
#include <unordered_map>

static std::unordered_map<GridCell::State, sf::Color> gridColors = {
	{GridCell::State::Empty, sf::Color::Black},
	{GridCell::State::Buffer, sf::Color(131,131,131,200)},
	{GridCell::State::Troop, sf::Color(0,120,0,255)},
	{GridCell::State::Defense, sf::Color(200,0,0,255)},
};

GridCell::GridCell(float size, GridCell::State state) : gridSquare(sf::Vector2f(size, size)) {
	this->setState(state);
	this->gridSquare.setOutlineColor(sf::Color::White);
	this->gridSquare.setOutlineThickness(2);
}

sf::RectangleShape& GridCell::getGridSquare() {
	return this->gridSquare;
}

GridCell::State GridCell::getState() const {
	return this->state;
}

void GridCell::setGridSquareSize(float size) {
	this->gridSquare.setSize(sf::Vector2f(size, size));
}

void GridCell::setGridSquarePosition(float x, float y) {
	this->gridSquare.setPosition(x, y);
}

void GridCell::setState(GridCell::State state) {
	this->state = state;
	this->gridSquare.setFillColor(gridColors[state]);
}
