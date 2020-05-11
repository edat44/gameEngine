//
// Created by edat44 on 5/4/20.
//

#ifndef GAME_SERVER_HPP
#define GAME_SERVER_HPP

#include <SFML/Network.hpp>
#include <thread>
#include <list>

#include <memory>
#include <network/Client.hpp>
#include <utils/Queue.hpp>
#include <game/Ticker.hpp>
#include <game/Engine.hpp>

namespace game::network {

class Server : public Ticker, public std::enable_shared_from_this<Server> {
public:
    explicit Server(int localPort, std::shared_ptr<game::Engine> engine);

    void Tick(sf::Time dt) override;

private:

    std::shared_ptr<Client> AddClient(const std::shared_ptr<sf::TcpSocket> &socket);

    std::unique_ptr<sf::TcpListener> listener;
    game::utils::List<std::shared_ptr<Client>> clients;
    std::shared_ptr<game::Engine> engine;
}; // class Server

} // ns game::network


#endif //GAME_SERVER_HPP
