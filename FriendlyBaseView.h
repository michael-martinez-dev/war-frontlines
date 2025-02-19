#pragma once
#include "BaseView.h"
#include "GridView.h"

class FriendlyBaseView : public BaseView, public GridView {
public:
	FriendlyBaseView(const User& user, const Base& base, sf::RenderWindow& window);
	void render(Game& game) override;
	void handleInput(Game& game) override;
	void handleGridClick(Game& game) override;
};
