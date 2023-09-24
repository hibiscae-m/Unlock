//
// Created by Marius on 24/09/2023.
//

#ifndef UNLOCK_GAME_H
#define UNLOCK_GAME_H

#include <SFML/Graphics.hpp>

class Game {
public:
    Game();
    void run();
private:
    void processEvents();
    void update(sf::Time deltaTime);
    void draw();
    sf::RenderWindow window;
};


#endif //UNLOCK_GAME_H
