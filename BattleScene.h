#pragma once
#include "GameState.h"

class BattleScene :
    public GameState
{
	void handleInput(Game& game) override;
	void update() override;
	void render(Game& game) override;
};

