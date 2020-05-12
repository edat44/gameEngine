//
// Created by edat44 on 5/5/20.
//

#ifndef GAME_QUEUE_HPP
#define GAME_QUEUE_HPP

#include <optional>
#include <iostream>
#include <mutex>
#include <memory>
#include <events/Event.hpp>
#include <containers/LinkedList.hpp>
#include <variant>
#include <SFML/Window/Event.hpp>

namespace game::containers {

template<typename T>
class Queue : public LinkedList<T> {
public:
    Queue() : LinkedList<T>() {}

    void Enqueue(T element);

    std::optional<T> Dequeue();
};

template<typename T>
void Queue<T>::Enqueue(T element) {
    this->PushBack(element);
}

template<typename T>
std::optional<T> Queue<T>::Dequeue() {
    return this->PopFront();
}

} // ns game::containers

#endif //GAME_QUEUE_HPP
