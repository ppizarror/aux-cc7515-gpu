#include <cassert>
#include "12_complex_v3.h"

int main() {
    // Inicializa
    Complex s(1, 1);
    Complex d(0, 1);

    // Experimento
    s = s + d;

    // Assert
    assert(s.getRealPart() == 1 and s.getImaginaryPart() == 2);
}