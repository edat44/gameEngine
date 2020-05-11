//
// Created by edat44 on 5/6/20.
//

#include <events/ClientMessageEvent.hpp>
#include <SFML/Network/IpAddress.hpp>
#include <iostream>
#include <sstream>

namespace game::events {

void ClientMessageEvent::Handle() {
    std::string extractedText;
    *this->packet >> extractedText;
    std::cout << "New client message ==> " << this->client->GetSocket()->getRemoteAddress() << ":" <<
              this->client->GetSocket()->getRemotePort() << "    '" << extractedText << "'" << std::endl;

    sf::Packet returnPacket;
    std::stringstream ss;
    ss << "Message received: '" << extractedText << "'";
    returnPacket << ss.str();
    this->client->GetSocket()->send(returnPacket);
}

} // ns game::events