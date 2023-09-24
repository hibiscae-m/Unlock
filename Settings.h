//
// Created by Marius on 24/09/2023.
//

#ifndef UNLOCK_SETTINGS_H
#define UNLOCK_SETTINGS_H

#include <string_view>

class Settings {
public:
    Settings() = delete;

    // Window
    static constexpr std::string_view WINDOW_NAME = "Unlock!";
    static constexpr unsigned short WINDOW_WIDTH = 1920;
    static constexpr unsigned short WINDOW_HEIGHT = 1080;
    static constexpr float WINDOW_FRAME_PER_SECOND = 1.f / 60;

    // Resources
    static constexpr std::string_view BUTTON_PLAY = "resources/graphics/menu/play_button.png";
    static constexpr std::string_view BUTTON_QUIT = "resources/graphics/menu/quit_button.png";
    static constexpr std::string_view BUTTON_SETTINGS = "resources/graphics/menu/settings_button.png";

    static constexpr std::string_view CARD_BACK = "resources/graphics/cards/back_0.png";
    static constexpr std::string_view CARD_CLUB_01 = "resources/graphics/cards/clubs_card_01.png";
};


#endif //UNLOCK_SETTINGS_H
