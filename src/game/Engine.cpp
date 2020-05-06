//
// Created by edat44 on 5/5/20.
//

#include <iostream>
#include <SFML/System/Sleep.hpp>
#include "game/Engine.hpp"

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
            std::cout << "Event of type: " << e.value()->GetType() << "!" << std::endl;
            e.value()->Handle();
        }
    }
}

void Engine::Stop() {
    this->running = false;
}

eventQueue_t Engine::Events() const {
    return this->events;
}