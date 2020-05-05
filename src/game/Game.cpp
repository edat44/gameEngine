//
// Created by edat44 on 4/20/20.
//

#include "game/Game.hpp"

Game::Game() {
    this->engine = new Engine();
    this->server = new Server(9003, this->engine->Events());
}


void Game::Start() {
    this->server->Start();
    this->engine->Run();
}

Game::~Game() {
    delete this->engine;

    this->server->Stop();
    delete this->server;
}