//
// Created by edat44 on 4/20/20.
//

#ifndef GAME_GAME_HPP
#define GAME_GAME_HPP

#include <network/Server.hpp>
#include <game/Engine.hpp>

namespace game {

class Game {
public:
    Game();

    ~Game();

    void Start();

private:
    std::shared_ptr<Engine> engine;
    std::shared_ptr<network::Server> server;

}; // class Game

} // ns game

#endif //GAME_GAME_HPP
