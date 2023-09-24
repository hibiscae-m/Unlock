//
// Created by Marius on 24/09/2023.
//

#ifndef UNLOCK_CARD_H
#define UNLOCK_CARD_H

#include "GraphicElements.h"
#include <string_view>
#include "Settings.h"
#include <SFML/Graphics.hpp>

class Card : public GraphicElements {
public:
    explicit Card(float posX = 0, float posY = 0);
    void update(sf::Time deltaTime, sf::Vector2i mousePosition) override;
private:
    void reactToClick() override;
    sf::Vector2f defaultScale = {10, 10};
    bool flipped = false;
    bool flipping = false;
    bool unflipping = false;

    void reactToDrag(sf::Vector2i mousePosition) override;
};


#endif //UNLOCK_CARD_H
