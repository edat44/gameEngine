//
// Created by edat44 on 5/5/20.
//

#include <iostream>
#include <events/ClientConnectedEvent.hpp>
#include <SFML/Network/IpAddress.hpp>

namespace game::events {

void ClientConnectedEvent::Handle() {
    std::cout << "New client ==> " << this->mClient->GetSocket()->getRemoteAddress() << ":" <<
              this->mClient->GetSocket()->getRemotePort() << std::endl;
}

} // ns game::events
