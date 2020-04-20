#include <SFML/Graphics.hpp>
#include <iostream>
#include <window.h>

// Starter program from https://www.sfml-dev.org/tutorials/2.5/start-linux.php
int main() {
    sf::RenderWindow window;
    cow::setupWindow(window, 400, 400, "Cowgame", 50, 50, sf::Style::Close & sf::Style::Titlebar);


    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen()) {
        sf::Event event = {};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                std::cout << "Closed!" << std::endl;
            }
        }
        window.clear();
        window.draw(shape);
        window.display();
    }
    return 0;
}
