class Complex {
public:
    explicit Complex(float real);

    Complex(float real, float imag);

    Complex();

    ~Complex();

    float getImaginaryPart() const;

    float getRealPart() const;

private:
    float m_realPart;
    float m_imaginaryPart;
};