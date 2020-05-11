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
    List() : LinkedList<T>(), headItr(this->head), tailItr(nullptr) {}
    void Insert(T element);
    NodeForwardIterator<T>& begin() { return this->headItr; }
    NodeForwardIterator<T>& end() { return this->tailItr; }
    NodeForwardIterator<T> erase(NodeForwardIterator<T> target);

private:
    void UpdateHeadItr();
    NodeForwardIterator<T> headItr;
    NodeForwardIterator<T> tailItr;
};

template <typename T>
void List<T>::UpdateHeadItr() {
    this->headItr = NodeForwardIterator(this->head);
}

template <typename T>
void List<T>::Insert(T element) {
    this->PushBack(element);
    this->UpdateHeadItr();
}

template <typename T>
NodeForwardIterator<T> List<T>::erase(NodeForwardIterator<T> target) {
    NodeForwardIterator<T> toReturn = target;
    for (auto itr = this->begin(); itr != this->end(); itr++) {
        if (itr == target) {
            auto node = *itr;
            std::cout << "Found node to erase!" << std::endl;
            if (itr->prev) {
                itr->prev->next = itr->next;
            }
            if (itr->next) {
                itr->next->prev = itr->prev;
            }
            auto newItr = NodeForwardIterator<T>(itr->next);
            delete *itr;
            toReturn = newItr;
            break;
        }
    }
    this->UpdateHeadItr();
    return toReturn;
}

} // ns game::utils

#endif //GAME_LIST_HPP
