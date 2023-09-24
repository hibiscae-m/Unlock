//
// Created by Marius on 24/09/2023.
//

#include "Game.h"
#include "Settings.h"
#include "GameManager.h"

Game::Game() :
    window(sf::VideoMode(Settings::WINDOW_WIDTH, Settings::WINDOW_HEIGHT),
           Settings::WINDOW_NAME.data(), sf::Style::Default)
{}

void Game::run() {
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    sf::Time framerate = sf::seconds(Settings::WINDOW_FRAME_PER_SECOND);
    GameManager::loadMenu();
    while (window.isOpen()) {
        timeSinceLastUpdate += clock.restart();
        if (timeSinceLastUpdate >= framerate) {
            timeSinceLastUpdate -= framerate;
            processEvents();
            update(framerate);
            draw();
        }
    }
}

void Game::processEvents() {
    sf::Event event{};
    while(window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }
}

void Game::update(sf::Time deltaTime) {
    GameManager::update(deltaTime, sf::Mouse::getPosition(window));
    if (GameManager::quitToDesktopRequested()) {
        window.close();
    }
}

void Game::draw() {
    window.clear();
    GameManager::draw(window);
    window.display();
}
