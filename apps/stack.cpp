
#include <iostream>

#include "containers/Stack.hpp"


// Starter program from https://www.sfml-dev.org/tutorials/2.5/start-linux.php
int main(int argc, char* argv[]) {
    Stack<int> stack;
    stack.Print();
    for (int i = 0; i < 21; i++) {
        stack.Push(i);
        stack.Print();
    }
    for (int i = 0; i < 22; i++) {
        std::optional<int> element = stack.Pop();
        if (element) {
            std::cout << "Removing " << element.value() << std::endl;
        } else {
            std::cout << "Stack is Empty!" << std::endl;
        }
    }
}
