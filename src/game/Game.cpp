//
// Created by edat44 on 4/20/20.
//

#include <game/Game.hpp>

namespace game {

Game::Game() {
    this->engine = std::make_shared<Engine>();
    this->server = std::make_shared<network::Server>(9003, this->engine->Events());
}


void Game::Start() {
    this->server->Start();
    this->engine->Run();
}

Game::~Game() {
    this->server->Stop();
}

} // ns game
