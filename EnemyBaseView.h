#pragma once
#include "BaseView.h"
#include "GridView.h"

class EnemyBaseView : public BaseView, public GridView
{
public:
	EnemyBaseView(const Base& base, sf::RenderWindow& window);
	void render(Game& game) override;
	void handleInput(Game& game) override;
	void handleGridClick(sf::RenderWindow& window) override;
};
