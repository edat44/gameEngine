//
// Created by edat44 on 5/4/20.
//

#ifndef GAME_STACK_HPP
#define GAME_STACK_HPP

#include <cstddef>
#include <algorithm>
#include <iostream>
#include <cassert>
#include <optional>

#define MIN_CAPACITY 10

template <typename T>
class Stack {
public:
    explicit Stack(size_t cap=MIN_CAPACITY) : data(nullptr), size(0), capacity(cap) {
        this->data = new T[this->capacity];
    }
    ~Stack();
    void push(const T &element);
    std::optional<T> pop();
    [[nodiscard]] bool empty() const;
    void print(std::ostream& out=std::cout) const;

    friend std::ostream& operator<<(std::ostream &out, const Stack &q) {
        out << "size: " << q.size << ", cap: " << q.capacity << std::endl;
        if (q.empty()) {
            std::cout << "<empty>";
        } else {
            for (size_t i = 0; i < q.size; i++) {
                out << q.data[i] << (i == q.size - 1 ? "" : ", ");
            }
        }
        out << std::endl;
        return out;
    }


private:
    int resize(size_t newCapacity);
    void adjustCapacity();

    T* data;
    size_t size;
    size_t capacity;
};

template <typename T>
Stack<T>::~Stack() {
    delete [] this->data;
    this->data = nullptr;
    this->size = 0;
}

template <typename T>
void Stack<T>::push(const T &element) {
    assert(this->data != nullptr);
    this->adjustCapacity();
    this->data[this->size++] = element;
}

template <typename T>
std::optional<T> Stack<T>::pop() {
    assert(this->data != nullptr);
    if (this->empty()) {
        return std::optional<T>();
    } else {
        T element = this->data[--this->size];
        this->adjustCapacity();
        return element;
    }
}

template<typename T>
bool Stack<T>::empty() const {
    return this->size == 0;
}

template <typename T>
void Stack<T>::print(std::ostream& out) const {
    out << *this;
}

template <typename T>
int Stack<T>::resize(size_t newCapacity) {
    assert(this->data != nullptr);

    T* newData = new T[newCapacity];
    std::copy(this->data, this->data + this->size, newData);
    delete [] this->data;

    this->data = newData;
    this->capacity = newCapacity;
    return this->capacity;
}

template <typename T>
void Stack<T>::adjustCapacity() {
    if (this->size >= this->capacity) {
        this->resize(this->size * 1.5);
    } else if (this->size <= this->capacity * 0.5) {
        this->resize(std::max((int)(this->size * 0.75), MIN_CAPACITY));
    }
}




#endif //GAME_STACK_HPP
