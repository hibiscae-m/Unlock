//
// Created by Marius on 24/09/2023.
//

#ifndef UNLOCK_GRAPHICELEMENTS_H
#define UNLOCK_GRAPHICELEMENTS_H

#include <SFML/Graphics.hpp>
#include <string_view>

class GraphicElements {
public:
    GraphicElements() = delete;
    explicit GraphicElements(std::string_view textureLocation, float posX = 0, float posY = 0);
    virtual ~GraphicElements() = default;
    void draw(sf::RenderWindow& window);
    virtual void update(sf::Time deltaTime, sf::Vector2i mousePosition);
    void callDestruction();
    bool isDestructed() const;
protected:
    sf::Sprite sprite;
    bool mouseOnSprite = false;
    sf::Time timeHoldingClick = sf::Time::Zero;
    sf::Time timeToDrag = sf::milliseconds(200);
    bool dragging = false;
private:
    bool destructed = false;
    bool clicking = false;
    virtual void reactToClick() {};
    virtual void reactToDrag(sf::Vector2i mousePosition) {};
};


#endif //UNLOCK_GRAPHICELEMENTS_H
