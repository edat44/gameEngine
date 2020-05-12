//
// Created by edat44 on 5/4/20.
//

#ifndef GAME_CLIENT_HPP
#define GAME_CLIENT_HPP


#include <SFML/System/NonCopyable.hpp>
#include <SFML/Network/TcpSocket.hpp>
#include <memory>

namespace game::network {

class Client : sf::NonCopyable {
public:
    Client() = delete;

    explicit Client(std::shared_ptr<sf::TcpSocket> socket) : mSocket(std::move(socket)) {}

    [[nodiscard]] std::shared_ptr<sf::TcpSocket> GetSocket() const;


private:
    std::shared_ptr<sf::TcpSocket> mSocket;

}; // class Client

} // ns game::network


#endif //GAME_CLIENT_HPP
