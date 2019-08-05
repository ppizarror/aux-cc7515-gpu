#include <iostream>

int main (void)
{
    // Variables
    int a = 5;
    int b = 10;

    // Pointers
    int *aPtr;
    aPtr = &a; // Get memory address

    std::cout << "a = " << a << std::endl;
    std::cout << "Address of a = " << &a << std::endl;
    std::cout << "aPtr = " << aPtr << std::endl;
    std::cout << "*aPtr = " << *aPtr << std::endl;

    return 0;
}
