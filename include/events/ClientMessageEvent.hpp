//
// Created by edat44 on 5/6/20.
//

#ifndef GAME_CLIENTMESSAGEEVENT_HPP
#define GAME_CLIENTMESSAGEEVENT_HPP


#include <memory>
#include <SFML/Network/TcpSocket.hpp>
#include <SFML/Network/Packet.hpp>
#include <utility>
#include <events/Event.hpp>
#include <network/Client.hpp>

namespace game::events {

class ClientMessageEvent : public Event {
public:
    ClientMessageEvent(std::shared_ptr<game::network::Client> client,
            std::shared_ptr<sf::Packet> packet) :
            Event("ClientMessageEvent"), mClient(std::move(client)), mPacket(std::move(packet)) {}

    void Handle() override;
private:
    std::shared_ptr<game::network::Client> mClient;
    std::shared_ptr<sf::Packet> mPacket;
};

} // ns game::events


#endif //GAME_CLIENTMESSAGEEVENT_HPP
