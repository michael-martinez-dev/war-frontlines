#pragma once
#include "BaseView.h"
#include "User.h"

class FriendlyHQView : public BaseView {
private:
	User& user;
	sf::Text troopQueueText;
	sf::Text defenseQueueText;
	sf::Text troopAvailText;
	sf::Text defenseAvailText;

public:
	FriendlyHQView(const Base& base, User& user);
	 
	void render(Game& game) override;
};

