#include <iostream>

class Complex
{
public:
    Complex(float real, float imag)
      : m_realPart(real),
        m_imaginaryPart(imag)
    {}

    float getImaginaryPart() const
    {
        return m_imaginaryPart;
    }

    float getRealPart() const
    {
        return m_realPart;
    }

private:
    float m_realPart;
    float m_imaginaryPart;
};

int main()
{
    Complex *c1 = new Complex(3, 5);
    Complex c2(2, 7);
    std::cout << "c1 = (" << c1->getRealPart() << ", " << c1->getImaginaryPart() << ")" << std::endl;
    std::cout << "c2 = (" << c2.getRealPart() << ", " << c2.getImaginaryPart() << ")" << std::endl;

    return 0;
}
