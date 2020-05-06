//
// Created by edat44 on 5/4/20.
//

#include "network/Client.hpp"

#include <utility>

Client::Client(std::shared_ptr<sf::TcpSocket> socket) {
    this->socket = std::move(socket);
}

std::shared_ptr<sf::TcpSocket> Client::GetSocket() const {
    return this->socket;
}
