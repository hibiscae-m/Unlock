//
// Created by Marius on 24/09/2023.
//

#ifndef UNLOCK_GAMEMANAGER_H
#define UNLOCK_GAMEMANAGER_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "GraphicElements.h"

static std::vector<std::unique_ptr<GraphicElements>> buffer;
static std::vector<std::unique_ptr<GraphicElements>> graphicElements;
static bool quitToDesktopRequest = false;

class GameManager {
public:
    GameManager() = delete;
    static void draw(sf::RenderWindow& window);
    static void update(sf::Time deltaTime, sf::Vector2i mousePosition);
    static void loadMenu();

    static void startGame();

    static void quitToDesktop();
    static bool quitToDesktopRequested();

private:
    static void clear();
};


#endif //UNLOCK_GAMEMANAGER_H
