cmake_minimum_required(VERSION 3.26)
project(Unlock)

set(CMAKE_CXX_STANDARD 20)

add_executable(Unlock main.cpp
        Game.cpp
        Game.h
        Settings.h
        GameManager.cpp
        GameManager.h
        ResourcesManager.cpp
        ResourcesManager.h
        GraphicElements.cpp
        GraphicElements.h
        PlayButton.cpp
        PlayButton.h
        MenuButtons.cpp
        MenuButtons.h
        QuitButton.cpp
        QuitButton.h
        SettingsButton.cpp
        SettingsButton.h
        Card.cpp
        Card.h
)

find_package(SFML COMPONENTS system window graphics audio CONFIG REQUIRED)
target_link_libraries(Unlock PRIVATE sfml-system sfml-network sfml-graphics sfml-window sfml-audio)