//
// Created by Marius on 24/09/2023.
//

#include "QuitButton.h"
#include "Settings.h"
#include "GameManager.h"

QuitButton::QuitButton(float posX, float posY) : MenuButtons(Settings::BUTTON_QUIT, posX, posY) {}

void QuitButton::reactToClick() {
    GameManager::quitToDesktop();
}
