//
// Created by Marius on 24/09/2023.
//

#ifndef UNLOCK_PLAYBUTTON_H
#define UNLOCK_PLAYBUTTON_H

#include "MenuButtons.h"

class PlayButton : public MenuButtons {
public:
    explicit PlayButton(float posX = 0, float posY = 0);
private:
    void reactToClick() override;
};


#endif //UNLOCK_PLAYBUTTON_H
