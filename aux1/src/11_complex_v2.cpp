#include <iostream>
#include "11_complex_v2.h"

Complex::Complex(float real, float imag)
        : m_realPart(real),
          m_imaginaryPart(imag) {}

Complex::Complex(float real)
        : m_realPart(real),
          m_imaginaryPart(0) {}

Complex::Complex()
        : m_realPart(0),
          m_imaginaryPart(0) {}

Complex::~Complex() {
    std::cout << "Destructor called." << std::endl;
}

float Complex::getImaginaryPart() const {
    return m_imaginaryPart;
}

float Complex::getRealPart() const {
    return this->m_realPart;
}