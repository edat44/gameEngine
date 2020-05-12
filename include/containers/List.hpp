//
// Created by edat44 on 5/5/20.
//

#ifndef GAME_LIST_HPP
#define GAME_LIST_HPP

#include <containers/LinkedList.hpp>
#include <containers/NodeForwardIterator.hpp>

namespace game::containers {

template <typename T>
class List : public LinkedList<T>{
public:
    List() : LinkedList<T>() {}
    void Insert(T element);
    NodeForwardIterator<T> begin() { return NodeForwardIterator<T>(this->mHead); }
    NodeForwardIterator<T> end() { return NodeForwardIterator<T>(nullptr); }
    NodeForwardIterator<T> erase(NodeForwardIterator<T> target);

    NodeForwardIterator<T> find(const T& val);
};

template <typename T>
void List<T>::Insert(T element) {
    this->PushBack(element);
}

template <typename T>
NodeForwardIterator<T> List<T>::erase(NodeForwardIterator<T> target) {
    for (auto itr = this->begin(); itr != this->end(); itr++) {
        if (itr == target) {
            Node<T>* node = itr.GetNode();
            std::cout << "Found node to erase!" << std::endl;
            if (node->mPrev) {
                node->mPrev->mNext = node->mNext;
            }
            if (node->mNext) {
                node->mNext->mPrev = node->mPrev;
            }
            auto toReturn = NodeForwardIterator<T>(node->mNext);
            delete node;
            return toReturn;
        }
    }
    return target;
}

template <typename T>
NodeForwardIterator<T> List<T>::find(const T& val) {
    for (auto it = this->begin(); it != this->end(); ++it) {
        if (*it == val) {
            return it;
        }
    }
    return this->end();
}

} // ns game::containers

#endif //GAME_LIST_HPP
