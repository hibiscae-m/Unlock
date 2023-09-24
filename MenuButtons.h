//
// Created by Marius on 24/09/2023.
//

#ifndef UNLOCK_MENUBUTTONS_H
#define UNLOCK_MENUBUTTONS_H

#include "GraphicElements.h"
#include <string_view>

class MenuButtons : public GraphicElements {
public:
    MenuButtons(std::string_view textureLocation, float posX = 0, float posY = 0);
    virtual void update(sf::Time deltaTime, sf::Vector2i mousePosition) override;
};


#endif //UNLOCK_MENUBUTTONS_H
