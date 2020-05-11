//
// Created by edat44 on 5/5/20.
//

#include <iostream>
#include <SFML/System/Sleep.hpp>
#include <game/Engine.hpp>

namespace game {


struct EventVisitor {
    void operator()(const std::shared_ptr<events::Event> &event) {
        std::cout << "Custom event of type: " << event->GetType() << "!" << std::endl;
        event->Handle();
    }

    void operator()(const std::shared_ptr<sf::Event> &event) {
        //std::cout << "SF event of type: " << event->type << "!" << std::endl;
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
    std::cout << dt.asMilliseconds() << " milliseconds, " << this->events->Size() << " events in queue" << std::endl;
    std::cout << "Tickers in list: " << this->tickers.Size() << std::endl;
    for (auto itr : this->tickers) {
        auto ticker = **itr;
        std::cout << "About to tick an item!" << std::endl;
        ticker->Tick(dt);
    }

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

void Engine::AddTicker(game::Ticker* ticker) {
    std::cout << "Adding a new ticker!" << std::endl;
    this->tickers.Insert(std::shared_ptr<game::Ticker>(ticker));
    std::cout << "done adding a new ticker!" << std::endl;
}

void Engine::AddEvent(std::shared_ptr<game::events::Event> event) {
    this->events->Enqueue(std::move(event));
}

} // ns game