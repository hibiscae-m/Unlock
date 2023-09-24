//
// Created by Marius on 24/09/2023.
//

#ifndef UNLOCK_QUITBUTTON_H
#define UNLOCK_QUITBUTTON_H

#include "MenuButtons.h"

class QuitButton : public MenuButtons {
public:
    explicit QuitButton(float posX = 0, float posY = 0);
private:
    void reactToClick() override;
};


#endif //UNLOCK_QUITBUTTON_H
