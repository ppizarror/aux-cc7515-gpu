#include <iostream>

// Declare function
double square(double num);

int main(void)
{
    double i = 4;
    double ii;

    ii = square(i);
    std::cout << "Value of i = " << i << std::endl;
    std::cout << "i^2 = i^i = " << ii << std::endl;

    return 0;
}

double square(double num)
{
    return num * num;
}
