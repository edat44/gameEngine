//
// Created by edat44 on 4/20/20.
//

#include <SFML/Window.hpp>

#ifndef GAME_WINDOW_H
#define GAME_WINDOW_H

namespace utils {

    // Setups a new window with extra parameters than the default sf::Window::create
    void SetupWindow(sf::Window &window, unsigned int width, unsigned int height,
                     const sf::String &title, int x, int y, sf::Uint32 style);

} // namespace utils


#endif //COWGAME_WINDOW_H
