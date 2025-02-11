#include "Game.h"
#include "MainMenu.h"
#include "WorldMap.h"
#include "FriendlyBaseView.h"
#include "EnemyBaseView.h"
#include "NeutralBaseView.h"
#include <iostream>


void Game::initEventMap() {
	this->eventMap[GameEvent::StartGame] = [this]() { 
		this->pushState(std::make_unique<WorldMap>());
		};
	this->eventMap[GameEvent::Return] = [this]() {
		this->popState();
		};
	this->eventMap[GameEvent::GoToFriendlyBase] = [this]() {
		Base selectedBase = dynamic_cast<WorldMap*>(this->states.top().get())->getSelectedBase();
		this->pushState(std::make_unique<FriendlyBaseView>(selectedBase));
		};
	this->eventMap[GameEvent::GoToEnemyyBase] = [this]() {
		Base selectedBase = dynamic_cast<WorldMap*>(this->states.top().get())->getSelectedBase();
		this->pushState(std::make_unique<EnemyBaseView>(selectedBase));
		};
	this->eventMap[GameEvent::GoToNeutralBase] = [this]() {
		Base selectedBase = dynamic_cast<WorldMap*>(this->states.top().get())->getSelectedBase();
		this->pushState(std::make_unique<NeutralBaseView>(selectedBase));
		};
	this->eventMap[GameEvent::ExitGame] = [this]() {
			window.close();
		};
}

Game::Game() : window(sf::VideoMode(1440, 720), "War Frontlines") {
	this->initEventMap();
	this->view = window.getDefaultView();
}

void Game::pushState(std::unique_ptr<GameState> state) {
	state->setEmitEventCallback([this](GameEvent event) {
			handleEvent(event); 
		});
	this->states.push(std::move(state));
}

void Game::popState() {
	if (this->states.size() > 1) {
		this->states.pop();
	}
}

void Game::changeState(std::unique_ptr<GameState> state) {
	this->popState();
	this->pushState(std::move(state));
}

std::unique_ptr<GameState>& Game::getCurrentState() {
	return this->states.top();
}

void Game::handleEvent(GameEvent event) {
	if (this->eventCoolDownClock.getElapsedTime().asMilliseconds() < 500) {
		return;
	}

	auto it = this->eventMap.find(event);
	if (it != eventMap.end()) {
		it->second();
	}
	else {
		std::cerr << "Unknown event\n";
	}

	this->eventCoolDownClock.restart();
}


void Game::run() {
	this->pushState(std::make_unique<MainMenu>());

	while (this->window.isOpen()) {
		sf::Event event;
		while (this->window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				this->window.close();
			}

			if (event.type == sf::Event::Resized) {
				sf::Vector2u newSize(event.size.width, event.size.height);
				this->view.setSize(newSize.x, newSize.y);
				this->view.setCenter(newSize.x / 2.0f, newSize.y / 2.0f);
				this->window.setView(this->view);
			}
		}

		this->window.clear();
		if (!states.empty()) {
			auto& currentState = this->states.top();
			currentState->update();
			currentState->render(*this);
			currentState->handleInput(*this);
		}

		this->window.display();
	}
}

sf::RenderWindow& Game::getWindow() {
	return this->window;
}
