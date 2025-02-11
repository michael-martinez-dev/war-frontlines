#pragma once
#include <SFML/Graphics.hpp>
#include <functional>


class Game;

enum class GameStateType {
	MainMenu,
	UserMenu,
	WorldMap,
	BattleScene,
};

enum class GameEvent {
	StartGame,
	OpenUserMenu,
	ExitGame,
	ReturnToMainMenu,
	ReturnToWorldMap,
	GoToFriendlyBase,
	GoToEnemyyBase,
	GoToNeutralBase,
};

class GameState
{
protected:
	std::function<void(GameEvent)> emitEvent;
public:
	virtual void handleInput(Game& game) = 0;
	virtual void update() = 0;
	virtual void render(Game& game) = 0;
	virtual ~GameState() = default;
	void setEmitEventCallback(std::function<void(GameEvent)> callback) {
			this->emitEvent = callback;
		}
};
