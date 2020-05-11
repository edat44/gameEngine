//
// Created by edat44 on 5/6/20.
//

#include <events/ClientMessageEvent.hpp>
#include <SFML/Network/IpAddress.hpp>
#include <iostream>

namespace game::events {

void ClientMessageEvent::Handle() {
    std::cout << "New client message ==> " << this->client->GetSocket()->getRemoteAddress() << ":" <<
              this->client->GetSocket()->getRemotePort() << std::endl;
    sf::Packet returnPacket;
    returnPacket << "Message received!";
    this->client->GetSocket()->send(returnPacket);
}

} // ns game::events