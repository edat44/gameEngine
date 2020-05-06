//
// Created by edat44 on 5/6/20.
//

#include <events/ClientMessageEvent.hpp>
#include <SFML/Network/IpAddress.hpp>
#include <iostream>

namespace game::events {

void ClientMessageEvent::Handle() {
    std::cout << "New client message ==> " << this->socket->getRemoteAddress() << ":" <<
              this->socket->getRemotePort() << std::endl;
    sf::Packet returnPacket;
    returnPacket << "Message received!";
    this->socket->send(returnPacket);
}

} // ns game::events