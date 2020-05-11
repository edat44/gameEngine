//
// Created by edat44 on 4/20/20.
//

#ifndef GAME_GAME_HPP
#define GAME_GAME_HPP

#include <network/Server.hpp>
#include <game/Engine.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <game/Ticker.hpp>

namespace game {

class Game : public Ticker {
public:
    Game();

    ~Game();

    void Start(int winWidth, int winHeight, int winX, int winY, const std::string &winTitle);

    void Tick(sf::Time dt) override;

private:
    std::shared_ptr<Engine> engine;
    std::shared_ptr<network::Server> server;
    std::shared_ptr<sf::RenderWindow> window;

}; // class Game

} // ns game

#endif //GAME_GAME_HPP
