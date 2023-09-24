//
// Created by Marius on 24/09/2023.
//

#include "GameManager.h"
#include "PlayButton.h"
#include "QuitButton.h"
#include "Settings.h"
#include "Card.h"

void GameManager::draw(sf::RenderWindow& window) {
    for (auto& graphicElement: graphicElements) {
        graphicElement->draw(window);
    }
}

void GameManager::update(sf::Time deltaTime, sf::Vector2i mousePosition) {
    for (auto& graphicElement: graphicElements) {
        graphicElement->update(deltaTime, mousePosition);
    }
    clear();
}

void GameManager::clear() {
    for (auto i = 0u; i < graphicElements.size(); i++) {
        if (graphicElements[i]->isDestructed()) {
            graphicElements.erase(graphicElements.begin() + i);
        }
    }
    for (auto& element: buffer) {
        graphicElements.push_back(std::move(element));
    }
    buffer.clear();
}

void GameManager::loadMenu() {
    buffer.push_back(std::make_unique<PlayButton>(Settings::WINDOW_WIDTH / 2,
                                                  Settings::WINDOW_HEIGHT / 4));
    buffer.push_back(std::make_unique<QuitButton>(Settings::WINDOW_WIDTH / 2,
                                                  Settings::WINDOW_HEIGHT / 4 * 3));
}

void GameManager::quitToDesktop() {
    quitToDesktopRequest = true;
}

bool GameManager::quitToDesktopRequested() {
    auto value = quitToDesktopRequest;
    return value;
}

void GameManager::startGame() {
    for (auto& graphicElement: graphicElements) {
        graphicElement->callDestruction();
    }
    buffer.push_back(std::make_unique<Card>(Settings::WINDOW_WIDTH / 2, Settings::WINDOW_HEIGHT / 2));
}
