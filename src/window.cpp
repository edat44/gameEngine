//
// Created by edat44 on 4/20/20.
//

#include "../include/window.h"

namespace cow {
    void setupWindow(sf::Window &window, unsigned int width, unsigned int height,
                     const sf::String &title, int x, int y, sf::Uint32 style = sf::Style::Default) {
        window.create(sf::VideoMode(width, height), title, style);
        window.setPosition({x, y});
        window.setActive(true);
        window.setVerticalSyncEnabled(true);
    }
}