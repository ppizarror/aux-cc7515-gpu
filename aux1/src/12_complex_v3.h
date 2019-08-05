#include <iostream>

class Complex
{
    friend std::ostream &operator<<(std::ostream &out, const Complex &complex);

public:
    Complex(float real, float imag);
    Complex operator+(Complex &complex) const;

    float getImaginaryPart() const;
    float getRealPart() const;

private:
    float m_realPart;
    float m_imaginaryPart;
};
