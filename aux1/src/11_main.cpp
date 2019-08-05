#include <iostream>
#include "11_complex_v2.h"

int main()
{
    Complex *c1 = new Complex(3, 5);
    Complex c2(2);
    Complex c3;
    std::cout << "c1 = (" << c1->getRealPart() << ", " << c1->getImaginaryPart() << ")" << std::endl;
    std::cout << "c2 = (" << c2.getRealPart() << ", " << c2.getImaginaryPart() << ")" << std::endl;
    std::cout << "c3 = (" << c3.getRealPart() << ", " << c3.getImaginaryPart() << ")" << std::endl;

    std::cout << "-----------------" << std::endl;
    std::cout << "Manual destruction of c1" << std::endl;
    delete c1;
    std::cout << "c1 is now destroyed" << std::endl;
    std::cout << "-----------------" << std::endl;

    std::cout << std::endl;

    std::cout << "On end of main():" << std::endl;
    std::cout << "-----------------" << std::endl;

    return 0;
}
