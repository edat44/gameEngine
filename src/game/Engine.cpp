//
// Created by edat44 on 5/5/20.
//

#include <iostream>
#include <SFML/System/Sleep.hpp>
#include "game/Engine.hpp"

namespace game {

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
    while (!this->events->Empty()) {
        auto e = this->events->Dequeue();
        if (e) {
            if (auto *eTest = std::get_if<std::shared_ptr<events::Event>>(&e.value())) {
                auto event = *eTest;
                std::cout << "Event of type: " << event->GetType() << "!" << std::endl;
                event->Handle();
            } else if (auto *eTest2 = std::get_if<std::shared_ptr<sf::Event>>(&e.value())) {
                auto event = *eTest2;
                std::cout << "Built in SF Event!" << std::endl;
            }
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