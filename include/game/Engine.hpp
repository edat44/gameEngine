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
    using EventType = std::variant<std::shared_ptr<events::Event>, std::shared_ptr<sf::Event>>;
    using EventQueueRawType = game::containers::Queue<EventType>;
    using EventQueueType = std::shared_ptr<EventQueueRawType>;

    Engine() : mRunning(false), mTickTime(sf::seconds(1.0 / 1.0)),
               mEvents(std::make_shared<EventQueueRawType>()) {}

    void Run();

    void Stop();

    [[nodiscard]] EventQueueType Events() const;

    void AddTickable(game::Tickable* tickable);
    void AddEvent(std::shared_ptr<game::events::Event>);

private:
    void Tick(sf::Time dt);

    bool mRunning;
    sf::Time mTickTime;
    EventQueueType mEvents;
    sf::Clock mClock;
    containers::List<std::shared_ptr<game::Tickable>> mTickables;
}; // class Engine

} // ns game


#endif //GAME_ENGINE_HPP
