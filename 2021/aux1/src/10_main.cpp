#include <iostream>
#include "10_complex_v1_sep.h"

int main() {
    auto *c1 = new Complex(3, 5);
    Complex c2(2, 7);
    std::cout << "c1 = (" << c1->getRealPart() << ", " << c1->getImaginaryPart() << ")" << std::endl;
    std::cout << "c2 = (" << c2.getRealPart() << ", " << c2.getImaginaryPart() << ")" << std::endl;
    return 0;
}