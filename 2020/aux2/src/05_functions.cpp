#include <iostream>

// Declara una función (el encabezado), esto podría hacerse en un .h
double square(double num);

double square(double num) {
    return num * num;
}

int main() {
    double i = 4;
    double ii;

    ii = square(i);
    std::cout << "Valor de i = " << i << std::endl;
    std::cout << "i^2 = i^i = " << ii << std::endl;

    return 0;
}