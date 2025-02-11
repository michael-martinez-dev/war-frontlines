#pragma once
#include "GameState.h"
#include "Base.h"


class NeutralBaseView : public GameState
{
private:
	Base base;
public:
	NeutralBaseView(const Base& base);
	void handleInput(Game& game) override;
	void render(Game& game) override;
};

