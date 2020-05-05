//
// Created by edat44 on 4/20/20.
//

#ifndef GAME_GAME_HPP
#define GAME_GAME_HPP

#include <network/Server.hpp>
#include <game/Engine.hpp>

class Game {
public:
    Game();
    ~Game();

    void Start();

private:
    Engine* engine;
    Server* server;
};

#endif //GAME_GAME_HPP
