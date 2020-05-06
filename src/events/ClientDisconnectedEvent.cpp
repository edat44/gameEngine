//
// Created by edat44 on 5/6/20.
//

#include <events/ClientDisconnectedEvent.hpp>
#include <SFML/Network/IpAddress.hpp>
#include <iostream>

namespace game::events {

void ClientDisconnectedEvent::Handle() {
    std::cout << "CLIENT DISCONNECTION ==> " << this->socket->getRemoteAddress() << ":" <<
              this->socket->getRemotePort() << std::endl;
}

} // ns game::events