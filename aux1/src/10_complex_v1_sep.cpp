#include "10_complex_v1_sep.h"

Complex::Complex(float real, float imag)
  : m_realPart(real),
    m_imaginaryPart(imag)
{}

float Complex::getImaginaryPart() const
{
    return m_imaginaryPart;
}

float Complex::getRealPart() const
{
    return this->m_realPart;
}
