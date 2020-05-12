//
// Created by edat44 on 5/5/20.
//

#ifndef GAME_ENGINE_HPP
#define GAME_ENGINE_HPP


#include <SFML/System/Time.hpp>
#include <SFML/System/Clock.hpp>
#include <containers/Queue.hpp>
#include <events/Event.hpp>
#include <containers/List.hpp>
#include <objects/Tickable.hpp>

namespace game {

class Engine {
public:
    Engine() : running(false), tickTime(sf::seconds(1.0 / 1.0)),
               events(std::make_shared<containers::eventRawQueue_t >()) {}

    void Run();

    void Stop();

    [[nodiscard]] containers::eventQueue_t Events() const;

    void AddTickable(game::Tickable* tickable);
    void AddEvent(std::shared_ptr<game::events::Event>);

private:
    void Tick(sf::Time dt);

    bool running;
    sf::Time tickTime;
    containers::eventQueue_t events;
    sf::Clock clock;
    containers::List<std::shared_ptr<game::Tickable>> tickables;
}; // class Engine

} // ns game


#endif //GAME_ENGINE_HPP
