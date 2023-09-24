//
// Created by Marius on 24/09/2023.
//

#include "Card.h"
#include "ResourcesManager.h"

Card::Card(float posX, float posY) : GraphicElements(Settings::CARD_BACK, posX, posY)
{
    sprite.setScale(defaultScale);
}

void Card::update(sf::Time deltaTime, sf::Vector2i mousePosition) {
    if (mouseOnSprite) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
            if (timeHoldingClick < timeToDrag) {
                sprite.setScale(sprite.getScale().x + 0.15f,
                                sprite.getScale().y + 0.15f);
            }
        }
    }
    if (!dragging)
        if (sprite.getScale().x > defaultScale.x && sprite.getScale().y > defaultScale.y) {
            sprite.setScale(sprite.getScale().x - 0.05f, sprite.getScale().y - 0.05f);
        }

    if (flipping) {
        if (!unflipping) {
            if (sprite.getScale().x >= 0) {
                sprite.setScale(sprite.getScale().x - 0.7f, sprite.getScale().y);
            }
            else {
                if (!flipped) {
                    sprite.setTexture(ResourcesManager<sf::Texture>::getResource(Settings::CARD_CLUB_01));
                    flipped = true;
                }
                else {
                    sprite.setTexture(ResourcesManager<sf::Texture>::getResource(Settings::CARD_BACK));
                    flipped = false;
                }
                unflipping = true;
            }
        }
        else {
            if (sprite.getScale().x < defaultScale.x) {
                sprite.setScale(sprite.getScale().x + 0.7f, sprite.getScale().y);
            }
            else {
                sprite.setScale(defaultScale);
                unflipping = false;
                flipping = false;
            }
        }
    }
    GraphicElements::update(deltaTime, mousePosition);
}

void Card::reactToClick() {
    flipping = true;
}

void Card::reactToDrag(sf::Vector2i mousePosition) {
    sprite.setPosition(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));
}
