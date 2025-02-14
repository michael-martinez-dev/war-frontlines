#pragma once
#include "BaseView.h"
#include "GridView.h"

class EnemyBaseView : public BaseView, public GridView
{
public:
	EnemyBaseView(const Base& base);
	void render(Game& game) override;
	void handleGridClick(sf::RenderWindow& window, sf::Event event) override;
};

