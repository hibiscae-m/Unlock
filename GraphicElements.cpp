//
// Created by Marius on 24/09/2023.
//

#include "GraphicElements.h"
#include "ResourcesManager.h"

GraphicElements::GraphicElements(std::string_view textureLocation, float posX, float posY) {
    sprite.setTexture(ResourcesManager<sf::Texture>::getResource(textureLocation));
    sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
    sprite.setPosition(posX, posY);
}

void GraphicElements::draw(sf::RenderWindow &window) {
    window.draw(sprite);
}

void GraphicElements::update(sf::Time deltaTime, sf::Vector2i mousePosition) {
    // Getting sprite's shape coordinates
    sf::Vector2f coordinatesX = {sprite.getPosition().x - sprite.getGlobalBounds().width / 2,
                                 sprite.getPosition().x + sprite.getGlobalBounds().width / 2};
    sf::Vector2f coordinatesY = {sprite.getPosition().y - sprite.getGlobalBounds().height / 2,
                                 sprite.getPosition().y + sprite.getGlobalBounds().height / 2};

    if (static_cast<float>(mousePosition.x) >= coordinatesX.x && static_cast<float>(mousePosition.x) <= coordinatesX.y &&
        static_cast<float>(mousePosition.y) >= coordinatesY.x && static_cast<float>(mousePosition.y) <= coordinatesY.y ) {
        mouseOnSprite = true;
    }
    else {
        mouseOnSprite = false;
    }

    if (mouseOnSprite) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
            timeHoldingClick += deltaTime;
            if (timeHoldingClick >= timeToDrag) {
                if (!dragging) {
                    dragging = true;
                }
            }
        }
        else {
            if (timeHoldingClick > sf::Time::Zero && timeHoldingClick < timeToDrag) {
                clicking = true;
            }
            timeHoldingClick = sf::Time::Zero;
            dragging = false;
        }
    }

    if (dragging) {
        reactToDrag(mousePosition);
    }

    if (clicking) {
        reactToClick();
        clicking = false;
    }
}

void GraphicElements::callDestruction() {
    destructed = true;
}

bool GraphicElements::isDestructed() const {
    return destructed;
}
