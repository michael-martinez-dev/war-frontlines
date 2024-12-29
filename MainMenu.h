#pragma once
#include "GameState.h"

class MainMenu :
    public GameState
{
    std::vector<std::string> options = {
        "Start Game",
        "Exit",
    };
    int selectedOption = 0;
    sf::Font font;
    sf::Clock inputClock;
    const float inputDeplay = 0.2f;

public:
    MainMenu();
    void handleInput(Game& game) override;
    void update() override;
    void render(Game& game) override;
};

