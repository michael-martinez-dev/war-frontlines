#pragma once
#include "BaseView.h"
#include "GridView.h"

class FriendlyBaseView : public BaseView, public GridView {
public:
	FriendlyBaseView(const Base& base);
	void render(Game& game) override;
	void handleInput(Game& game) override;
	void handleGridClick(sf::RenderWindow& window, sf::Event event) override;
};
