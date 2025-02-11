#pragma once
#include <SFML/Graphics.hpp>

class Base
{
public:
    enum class BaseType {
        Friendly,
        Enemy,
        Neutral,
        FriendlyHQ,
        EnemyHQ,
    };

    Base(std::string name, sf::Vector2f position, BaseType type);
    std::string getName() const;
    sf::Vector2f getPosition() const;
    BaseType getType() const;
    static std::vector<Base> getExampleBases();
    void setName(std::string name);
    void setPosition(sf::Vector2f position);
    void setPosition(float x, float y);
    void setType(BaseType type);

private:
    std::string name;
    sf::Vector2f position;
    BaseType type;

};

