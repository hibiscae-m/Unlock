//
// Created by Marius on 24/09/2023.
//

#include "MenuButtons.h"

MenuButtons::MenuButtons(std::string_view textureLocation, float posX, float posY) : GraphicElements(textureLocation,
                                                                                                     posX, posY) {}

void MenuButtons::update(sf::Time deltaTime, sf::Vector2i mousePosition) {
    GraphicElements::update(deltaTime, mousePosition);
    if (mouseOnSprite) {
        sprite.setScale(1.2, 1.2);
    }
    else {
        sprite.setScale(1, 1);
    }
}
