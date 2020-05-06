//
// Created by edat44 on 5/5/20.
//

#include <iostream>
#include <SFML/System/Sleep.hpp>
#include "game/Engine.hpp"

namespace game {


struct EventVisitor {
    void operator()(const std::shared_ptr<events::Event> &event) {
        std::cout << "Custom event of type: " << event->GetType() << "!" << std::endl;
        event->Handle();
    }

    void operator()(const std::shared_ptr<sf::Event> &event) {
        std::cout << "SF event of type: " << event->type << "!" << std::endl;
    }
};

void Engine::Run() {
    this->running = true;
    this->clock.restart();
    while (this->running) {
        sf::Time elapsed = this->clock.restart();
        this->Tick(elapsed);
        sf::Time remaining = this->tickTime - this->clock.getElapsedTime();
        if (remaining > sf::Time::Zero) {
            sf::sleep(remaining);
        }
    }
}

void Engine::Tick(sf::Time dt) {
    std::cout << dt.asMilliseconds() << " milliseconds!" << std::endl;
    while (!this->events->Empty() && this->clock.getElapsedTime() < this->tickTime) {
        auto e = this->events->Dequeue();
        if (e) {
            std::visit(EventVisitor{}, e.value());
        }
    }
}

void Engine::Stop() {
    this->running = false;
}

utils::eventQueue_t Engine::Events() const {
    return this->events;
}

} // ns game