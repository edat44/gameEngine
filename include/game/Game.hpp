//
// Created by edat44 on 4/20/20.
//

#ifndef GAME_GAME_HPP
#define GAME_GAME_HPP

#include <network/Server.hpp>
#include <game/Engine.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <objects/Tickable.hpp>

namespace game {

class Game {
public:
    Game();

    ~Game();

    void Start(int winWidth, int winHeight, int winX, int winY, const std::string &winTitle);

    void Tick(sf::Time dt);

private:
    std::shared_ptr<Engine> mEngine;
    std::shared_ptr<network::Server> mServer;
    std::shared_ptr<sf::RenderWindow> mWindow;

}; // class Game

} // ns game

#endif //GAME_GAME_HPP
