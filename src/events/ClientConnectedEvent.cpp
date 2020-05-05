//
// Created by edat44 on 5/5/20.
//

#include <iostream>
#include <events/ClientConnectedEvent.hpp>
#include <SFML/Network/IpAddress.hpp>

void ClientConnectedEvent::Handle() {
    std::cout << "New client ==> " << this->socket->getRemoteAddress() << ":" <<
                 this->socket->getRemotePort() << std::endl;
}
