
#include <iostream>

#include "utils/Queue.hpp"


// Starter program from https://www.sfml-dev.org/tutorials/2.5/start-linux.php
int main(int argc, char* argv[]) {
    Queue<int> q;
    q.print();
    for (int i = 0; i < 21; i++) {
        q.enqueue(i);
        q.print();
    }
    for (int i = 0; i < 22; i++) {
        std::optional<int> element = q.dequeue();
        if (element) {
            std::cout << "Removed " << element.value() << std::endl;
        } else {
            std::cout << "Stack is empty!" << std::endl;
        }
        q.print();
    }
    q.enqueue(5);
    q.print();
}
