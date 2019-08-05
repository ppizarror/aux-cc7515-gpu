#include <iostream>
#include "12_complex_v3.h"

Complex::Complex(float real, float imag)
  : m_realPart(real),
    m_imaginaryPart(imag)
{}

std::ostream& operator<<(std::ostream& out, const Complex &complex)
{
    out << "(" << complex.getRealPart() << ", " << complex.getImaginaryPart() << ")";
    return out;
}

Complex Complex::operator+(Complex &complex) const
{
    return Complex(this->m_realPart + complex.m_realPart,
                   this->m_imaginaryPart + complex.m_imaginaryPart);
}

float Complex::getImaginaryPart() const
{
    return m_imaginaryPart;
}

float Complex::getRealPart() const
{
    return this->m_realPart;
}
