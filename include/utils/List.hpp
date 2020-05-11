//
// Created by edat44 on 5/5/20.
//

#ifndef GAME_LIST_HPP
#define GAME_LIST_HPP

#include <utils/LinkedList.hpp>

namespace game::utils {

template <typename T>
class List : public LinkedList<T>{
public:
    List() : LinkedList<T>() {}
    void Insert(T element);
    NodeForwardIterator<T> begin() { return NodeForwardIterator<T>(this->head); }
    NodeForwardIterator<T> end() { return NodeForwardIterator<T>(nullptr); }
    NodeForwardIterator<T> erase(NodeForwardIterator<T> target);
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
            if (node->prev) {
                node->prev->next = node->next;
            }
            if (node->next) {
                node->next->prev = node->prev;
            }
            auto toReturn = NodeForwardIterator<T>(node->next);
            delete node;
            return toReturn;
        }
    }
    return target;
}

} // ns game::utils

#endif //GAME_LIST_HPP
