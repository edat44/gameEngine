
#include <iostream>

#include "utils/Stack.hpp"


// Starter program from https://www.sfml-dev.org/tutorials/2.5/start-linux.php
int main(int argc, char* argv[]) {
    Stack<int> stack;
    stack.print();
    for (int i = 0; i < 21; i++) {
        stack.push(i);
        stack.print();
    }
    for (int i = 0; i < 22; i++) {
        std::optional<int> element = stack.pop();
        if (element) {
            std::cout << "Removing " << element.value() << std::endl;
        } else {
            std::cout << "Stack is empty!" << std::endl;
        }
    }
}
