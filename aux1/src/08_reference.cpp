#include <iostream>

int main() {
    // Variables
    int a = 5;

    // References
    int &aRef = a;
    std::cout << "a = " << a << std::endl;
    std::cout << "aRef = " << aRef << std::endl;

    // Modifica variable
    a = 7;
    std::cout << "a = " << a << std::endl;
    std::cout << "aRef = " << aRef << std::endl;

    // Modifica referencia
    aRef = 8;
    std::cout << "a = " << a << std::endl;
    std::cout << "aRef = " << aRef << std::endl;

    return 0;
}