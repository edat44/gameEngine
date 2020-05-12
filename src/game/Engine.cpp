//
// Created by edat44 on 5/5/20.
//

#include <iostream>
#include <SFML/System/Sleep.hpp>
#include <game/Engine.hpp>
#include <objects/Tickable.hpp>
#include <functional>

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
    this->mRunning = true;
    this->mClock.restart();
    while (this->mRunning) {
        sf::Time elapsed = this->mClock.restart();
        this->Tick(elapsed);
        sf::Time remaining = this->mTickTime - this->mClock.getElapsedTime();
        if (remaining > sf::Time::Zero) {
            sf::sleep(remaining);
        }
    }
}

void Engine::Tick(sf::Time dt) {
    std::cout << dt.asMilliseconds() << " milliseconds, " << this->mEvents->Size() << " events in queue" << std::endl;
    std::cout << "Objects in list: " << this->mTickables.Size() << std::endl;
    for (auto& tickable : this->mTickables) {
        tickable->Tick(dt);
    }

    while (!this->mEvents->Empty() && this->mClock.getElapsedTime() < this->mTickTime) {
        auto e = this->mEvents->Dequeue();
        if (e) {
            std::visit(EventVisitor{}, e.value());
        }
    }
}

void Engine::Stop() {
    this->mRunning = false;
}

Engine::EventQueueType Engine::Events() const {
    return this->mEvents;
}

void Engine::AddTickable(game::Tickable* tickable) {
    this->mTickables.Insert(std::shared_ptr<game::Tickable>(tickable));
}

void Engine::AddEvent(std::shared_ptr<game::events::Event> event) {
    std::cout << "\t\tAdding new event of type " << event->GetType() << std::endl;
    this->mEvents->Enqueue(std::move(event));
}

} // ns game