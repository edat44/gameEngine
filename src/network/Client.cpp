//
// Created by edat44 on 5/4/20.
//

#include "network/Client.hpp"

Client::Client(sf::TcpSocket* socket) {
    this->socket = std::shared_ptr<sf::TcpSocket>(socket);
}

std::shared_ptr<sf::TcpSocket> Client::GetSocket() const {
    return this->socket;
}
