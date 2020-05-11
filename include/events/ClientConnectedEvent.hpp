//
// Created by edat44 on 5/5/20.
//

#ifndef GAME_CLIENTCONNECTEDEVENT_HPP
#define GAME_CLIENTCONNECTEDEVENT_HPP

#include <memory>
#include <events/Event.hpp>
#include <network/Client.hpp>

namespace game::events {

class ClientConnectedEvent : public Event {
public:
    explicit ClientConnectedEvent(std::shared_ptr<game::network::Client> client) :
            Event("ClientConnectedEvent"), client(std::move(client)) {}

    void Handle() override;

private:
    std::shared_ptr<game::network::Client> client;
};

} // ns game::events


#endif //GAME_CLIENTCONNECTEDEVENT_HPP
