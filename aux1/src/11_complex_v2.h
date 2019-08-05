class Complex
{
public:
    Complex(float real, float imag);
    Complex(float real);
    Complex();
    ~Complex();
    float getImaginaryPart() const;
    float getRealPart() const;

private:
    float m_realPart;
    float m_imaginaryPart;
};
