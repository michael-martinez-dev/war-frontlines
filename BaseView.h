#pragma once
#include "GameState.h"
#include "Base.h"
#include "GridCell.h"
#include <SFML/Graphics.hpp>


class BaseView : public GameState
{
protected:
	Base base;
	sf::Font  font;
	sf::Text baseInfoText;
	sf::RectangleShape  baseGridOutline;
	sf::Clock  inputClock;
	const float inputDelay = 0.2f;


	void setupBaseInfoText(const std::string& type);

public:
	BaseView(const Base& base, const std::string& type);
	void handleInput(Game& game) override;
	void update() override;
	void render(Game& game);
};

