#pragma once
#include "GameState.h"
#include "Base.h"


class NeutralBaseView : public GameState
{
private:
	Base base;
	sf::Font font;
	sf::Text baseInfoText;
	sf::Clock inputClock;
	const float inputDeplay = 0.2f;

public:
	NeutralBaseView(const Base& base);
	void handleInput(Game& game) override;
	void update() override;
	void render(Game& game) override;
};

