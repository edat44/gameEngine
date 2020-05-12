//
// Created by edat44 on 5/5/20.
//

#ifndef GAME_NODE_HPP
#define GAME_NODE_HPP

#include <cassert>

namespace game::containers {

template <typename T>
class Node {
public:
    Node() = delete;
    explicit Node(T data) : mData(data), mNext(nullptr), mPrev(nullptr) {}
    T mData;
    Node<T>** Next() { return &mNext; }
    Node<T>** Prev() { return &mPrev; }
    Node<T>* mNext;
    Node<T>* mPrev;

    T& operator*() {
        return this->mData;
    }

    T& operator->() {
        return this->mData;
    }
};


} // ns game::containers

#endif //GAME_NODE_HPP
