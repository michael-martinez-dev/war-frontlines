#pragma once
#include "GameState.h"
#include "Base.h"

class WorldMap :
    public GameState
{
    sf::Texture mapTexture;
    sf::Sprite mapSprite;
    sf::Font font;
    sf::Clock initClock;
    sf::Clock inputClock;
    int baseSelected = 0;
    const float inputDeplay = 0.3f;
    std::vector<Base> bases = Base::getExampleBases();
    sf::Color getBaseColor(Base::BaseType baseType);
    int getBaseClicked(sf::RenderWindow& window);
    void emitBaseSelected();

public:
    WorldMap();
    void handleInput(Game& game) override;
    void update() override;
    void render(Game& game) override;
    Base getSelectedBase();
};

