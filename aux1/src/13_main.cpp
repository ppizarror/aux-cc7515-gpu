#include <iostream>
#include "13_stack.h"
#include "12_complex_v3.h"

int main() {
    Stack<Complex> stack;
    Complex c1(1.1, 2.2);

    std::cout << "On start, size of stack = " << stack.size() << std::endl;

    stack.push(c1);

    std::cout << "On progress, size of stack = " << stack.size() << std::endl;

    Complex c2 = stack.pop();

    std::cout << "c1 = " << c1 << std::endl;
    std::cout << "c2 = " << c2 << std::endl;

    std::cout << "On end, size of stack = " << stack.size() << std::endl;

    return 0;
  }

