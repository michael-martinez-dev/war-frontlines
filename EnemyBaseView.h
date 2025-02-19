#pragma once
#include "BaseView.h"
#include "GridView.h"
#include "EnemyUser.h"

class EnemyBaseView : public BaseView, public GridView
{
public:
	EnemyBaseView(EnemyUser& eUser, const Base& base, sf::RenderWindow& window);
	void render(Game& game) override;
	void handleInput(Game& game) override;
	void handleGridClick(Game& game) override;
};
