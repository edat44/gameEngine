//
// Created by edat44 on 5/4/20.
//

#include "network/Client.hpp"

#include <utility>

namespace game::network {

std::shared_ptr<sf::TcpSocket> Client::GetSocket() const {
    return this->socket;
}

} // ns game::network
