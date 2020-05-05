//
// Created by edat44 on 5/4/20.
//

#ifndef GAME_CLIENT_HPP
#define GAME_CLIENT_HPP


#include <SFML/System/NonCopyable.hpp>
#include <SFML/Network/TcpSocket.hpp>
#include <memory>

class Client : sf::NonCopyable {
public:
    Client() = delete;
    explicit Client(sf::TcpSocket* socket);

    [[nodiscard]] std::shared_ptr<sf::TcpSocket> GetSocket() const;


private:
    std::shared_ptr<sf::TcpSocket> socket;
};


#endif //GAME_CLIENT_HPP
