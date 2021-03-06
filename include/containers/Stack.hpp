//
// Created by edat44 on 5/4/20.
//

#ifndef GAME_STACK_HPP
#define GAME_STACK_HPP

#include <optional>
#include <containers/LinkedList.hpp>

namespace game::containers {

template <typename T>
class Stack : public LinkedList<T> {
public:
    Stack() : LinkedList<T>() {}
    void Push(const T &element);
    std::optional<T> Pop();
};

template <typename T>
void Stack<T>::Push(const T &element) {
    this->PushBack(element);
}

template <typename T>
std::optional<T> Stack<T>::Pop() {
    return this->PopBack();
}

} // ns game::containers


#endif //GAME_STACK_HPP
