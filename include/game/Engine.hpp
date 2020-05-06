//
// Created by edat44 on 5/5/20.
//

#ifndef GAME_ENGINE_HPP
#define GAME_ENGINE_HPP


#include <SFML/System/Time.hpp>
#include <SFML/System/Clock.hpp>
#include <utils/Queue.hpp>
#include <events/Event.hpp>

namespace game {

class Engine {
public:
    Engine() : running(false), tickTime(sf::seconds(1.0 / 1.0)),
               events(std::make_shared<utils::eventRawQueue_t >()) {}

    void Run();

    void Stop();

    [[nodiscard]] utils::eventQueue_t Events() const;

private:
    void Tick(sf::Time dt);

    bool running;
    sf::Time tickTime;
    utils::eventQueue_t events;
    sf::Clock clock;
}; // class Engine

} // ns game


#endif //GAME_ENGINE_HPP
