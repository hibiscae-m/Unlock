//
// Created by Marius on 24/09/2023.
//

#include "PlayButton.h"
#include "Settings.h"
#include "GameManager.h"

PlayButton::PlayButton(float posX, float posY) : MenuButtons(Settings::BUTTON_PLAY, posX, posY) {}

void PlayButton::reactToClick() {
    GameManager::startGame();
}