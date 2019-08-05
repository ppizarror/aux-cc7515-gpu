#include <iostream>

int main() {
    // Comparaciones
    int C = 5;
    if (C < 5) {
        std::cout << "C es menor que 5" << std::endl;
    } else if (C > 5) {
        std::cout << "C es mayor que 5" << std::endl;
    } else // C == 5
    {
        std::cout << "C es 5" << std::endl;
    }
    return 0;
}