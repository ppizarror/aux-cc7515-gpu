#include <iostream>

int main() {
    // While
    int i = 0;
    while (i < 5) {
        std::cout << "i = " << i << std::endl;
        i++;
    }

    // For
    for (int j = 0; j < 5; j++) {
        std::cout << "j = " << j << std::endl;
    }

    return 0;
}