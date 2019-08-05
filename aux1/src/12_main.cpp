#include <iostream>
#include "12_complex_v3.h"

int main() {
    Complex c1(3, 5);
    Complex c2(2, 8);
    Complex c3(0, 0);

    std::cout << "c1 = " << c1 << std::endl;
    std::cout << "c2 = " << c2 << std::endl;
    std::cout << "c3 = " << c3 << std::endl;
    c3 = c1 + c2;

    std::cout << "Ahora c3 = c1 + c2 = " << c3 << std::endl;
    return 0;
}