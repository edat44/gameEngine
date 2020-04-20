//
// Created by edat44 on 4/20/20.
//

#include <SFML/Window.hpp>

#ifndef COWGAME_WINDOW_H
#define COWGAME_WINDOW_H

namespace cow {

    // Setups a new window with extra parameters than the default sf::Window::create
    void setupWindow(sf::Window &window, unsigned int width, unsigned int height,
                     const sf::String &title, int x, int y, sf::Uint32 style);

}


#endif //COWGAME_WINDOW_H
