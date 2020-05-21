/**  A generic LinkedList Datastructure
 *
 * #include "containers/LinkedList.hpp" <BR>
 *
 * Creates a double linked list of type <T> using the Node class.
 * Sub classes can create their own public interfaces to create various Abstract Data Types
 *
 * @Node.hpp
 */

#ifndef GAME_LINKEDLIST_HPP
#define GAME_LINKEDLIST_HPP

#include <functional>
#include <iostream>
#include <memory>
#include <mutex>
#include <optional>

#include <containers/Node.hpp>


namespace game::containers {

template <typename T>
class LinkedList {
public:
    using NodeType = Node<T>;
    using SizeType = size_t;

// LIFECYCLE
    LinkedList() : mHead(nullptr), mTail(nullptr), mSize(0) {}
    ~LinkedList();

// OPERATORS
    friend std::ostream& operator<<(std::ostream &out, const LinkedList &list) {
        std::lock_guard<std::mutex> l(list.mLock);
        out << "size: " << list.mSize << std::endl;
        if (list.Empty()) {
            out << "<Empty>";
        } else {
            for (NodeType curr = list.mHead; curr; curr = curr->mNext) {
                out << curr->mData;
                if (curr->mNext) {
                    out << ", ";
                }
            }
        }
        out << std::endl;
        return out;
    }

    /* Empty
     *
     * @return true if there are no elements in the LinkedList
     */
    [[nodiscard]] bool Empty() const;

    /* Print
     *
     * @param out The output stream to print to
     * @return void
     */
    void Print(std::ostream& out= std::cout) const;

    /* Size
     *
     * @return The number of elements in the LinkedList
     */
    [[nodiscard]] SizeType Size() const;



protected:
    void PushBack(T element);
    void PushFront(T element);
    void Push(T element, NodeType* &front, NodeType* &back,
              std::function<NodeType**(NodeType*)> next, std::function<NodeType**(NodeType*)> prev);

    std::optional<T> PopFront();
    std::optional<T> PopBack();
    std::optional<T> Pop(NodeType* &front, NodeType* &back,
            std::function<NodeType**(NodeType*)> next, std::function<NodeType**(NodeType*)> prev);

    NodeType* mHead;
    NodeType* mTail;
    SizeType mSize;
};

template <typename T>
LinkedList<T>::~LinkedList() {
    NodeType* curr = mHead;
    NodeType* next = curr;
    while (curr) {
        next = curr->mNext;
        delete curr;
        curr = next;
    }
}

template <typename T>
bool LinkedList<T>::Empty() const {
    return mSize == 0;
}

template <typename T>
typename LinkedList<T>::SizeType LinkedList<T>::Size() const {
    return mSize;
}

template <typename T>
void LinkedList<T>::PushFront(T element) {
    Push(element, mHead, mTail, &Node<T>::Next, &Node<T>::Prev);
}

template <typename T>
void LinkedList<T>::PushBack(T element) {
    return Push(element, mTail, mHead, &Node<T>::Prev, &Node<T>::Next);
}

template <typename T>
void LinkedList<T>::Push(T element, NodeType* &front, NodeType* &back,
                         std::function<NodeType**(NodeType*)> next,
                         std::function<NodeType**(NodeType*)> prev) {
    auto node = new Node(element);
    if (Empty()) {
        front = node;
        back = node;
    } else {
        *prev(front) = node;
        *next(node) = front;
        front = node;
    }
    mSize++;
}

template <typename T>
std::optional<T> LinkedList<T>::PopFront() {
    return Pop(mHead, mTail, &Node<T>::Next, &Node<T>::Prev);
}

template <typename T>
std::optional<T> LinkedList<T>::PopBack() {
    return Pop(mTail, mHead, &Node<T>::Prev, &Node<T>::Next);
}

template<typename T>
std::optional<T> LinkedList<T>::Pop(NodeType* &front, NodeType* &back,
        std::function<Node<T>**(NodeType*)> next, std::function<Node<T>**(NodeType*)> prev) {
    if (Empty()) {
        return std::optional<T>();
    } else {
        T data = front->mData;
        NodeType* newHead = *next(front);
        delete front;
        mSize--;
        if (Empty()) {
            front = nullptr;
            back = nullptr;
        } else {
            front = newHead;
            *prev(front) = nullptr;
        }
        return data;
    }
}

template <typename T>
void LinkedList<T>::Print(std::ostream& out) const {
    out << *this;
}

} // ns game::containers

#endif //GAME_LINKEDLIST_HPP
