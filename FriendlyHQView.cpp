#include "FriendlyHQView.h"
#include "Game.h"


FriendlyHQView::FriendlyHQView(const Base& base, User& user) : BaseView(base, "FriendlyHQ"), user(user) {
    this->troopQueueText.setFont(font);
    this->troopQueueText.setCharacterSize(32);
    this->troopQueueText.setFillColor(sf::Color::White);
    this->troopQueueText.setPosition(50, 150);
    this->troopQueueText.setStyle(sf::Text::Style::Bold);

    this->defenseQueueText.setFont(font);
    this->defenseQueueText.setCharacterSize(32);
    this->defenseQueueText.setFillColor(sf::Color::White);
    this->defenseQueueText.setPosition(50, 250);
    this->defenseQueueText.setStyle(sf::Text::Style::Bold);

    this->troopAvailText.setFont(font);
    this->troopAvailText.setCharacterSize(32);
    this->troopAvailText.setFillColor(sf::Color::White);
    this->troopAvailText.setPosition(50, 350);
    this->troopAvailText.setStyle(sf::Text::Style::Bold);

    this->defenseAvailText.setFont(font);
    this->defenseAvailText.setCharacterSize(32);
    this->defenseAvailText.setFillColor(sf::Color::White);
    this->defenseAvailText.setPosition(50, 450);
    this->defenseAvailText.setStyle(sf::Text::Style::Bold);
}


void FriendlyHQView::render(Game& game) {
	sf::RenderWindow& window = game.getWindow();
    this->troopQueueText.setString("Troops Training: " + std::to_string(user.getQueuedTroops()));
    this->defenseQueueText.setString("Defenses Building: " + std::to_string(user.getQueuedDefenses()));

    this->troopAvailText.setString("Troops Available: " + std::to_string(user.getAvailableTroops()));
    this->defenseAvailText.setString("Defenses Available: " + std::to_string(user.getAvailableDefenses()));

    window.draw(this->baseInfoText);
    window.draw(this->troopQueueText);
    window.draw(this->defenseQueueText);
    window.draw(this->troopAvailText);
    window.draw(this->defenseAvailText);
}

