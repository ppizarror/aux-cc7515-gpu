#include <iostream>

int main (void)
{
    // Variables
    int a = 5;

    // References
    int &aRef = a;
    std::cout << "a = " << a << std::endl;
    std::cout << "aRef = " << aRef << std::endl;

    // Modify variable
    a = 7;
    std::cout << "a = " << a << std::endl;
    std::cout << "aRef = " << aRef << std::endl;

    // Modify reference
    aRef = 8;
    std::cout << "a = " << a << std::endl;
    std::cout << "aRef = " << aRef << std::endl;

    return 0;
}
