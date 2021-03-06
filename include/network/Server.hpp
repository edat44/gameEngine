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
#include <containers/Queue.hpp>
#include <objects/Tickable.hpp>
#include <game/Engine.hpp>

namespace game::network {

class Server : public Tickable {
public:
    explicit Server(int localPort, std::shared_ptr<game::Engine> engine);

    ~Server();

    void Tick(sf::Time dt) override;

private:

    std::shared_ptr<Client> AddClient(const std::shared_ptr<sf::TcpSocket> &socket);

    std::unique_ptr<sf::TcpListener> mListener;
    game::containers::List<std::shared_ptr<Client>> mClients;
    std::shared_ptr<game::Engine> mEngine;
}; // class Server

} // ns game::network


#endif //GAME_SERVER_HPP
