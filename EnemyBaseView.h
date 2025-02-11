#pragma once
#include "GameState.h"
#include "Base.h"

class EnemyBaseView : public GameState
{
private:
	Base base;

public:
	EnemyBaseView(const Base& base);
	void handleInput(Game& game) override;
	void render(Game& game) override;
};

