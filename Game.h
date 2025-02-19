#pragma once
#include "GameState.h"
#include "User.h"
#include "EnemyUser.h"
#include <SFML/Graphics.hpp>
#include <stack>
#include <unordered_map>
#include <functional>


class Game
{
	std::stack<std::unique_ptr<GameState>> states;
	std::unordered_map<GameEvent, std::function<void()>> eventMap;
	sf::RenderWindow window;
	sf::View view;
	sf::Clock eventCoolDownClock;

	User user;
	EnemyUser eUser;

public:
	Game();
	void initEventMap();
	void pushState(std::unique_ptr<GameState> state);
	void popState();
	void changeState(std::unique_ptr<GameState> state);
	std::unique_ptr<GameState>& getCurrentState();
	void handleEvent(GameEvent event);
	void run();
	sf::RenderWindow& getWindow();
	User& getUser();
	void setUser(User& user);
	EnemyUser& getEnemyUser();
	void setEnemyUser(EnemyUser& eUser);
};
