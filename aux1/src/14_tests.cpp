#include <cassert>
#include "12_complex_v3.h"

int main() {
    // Initialize
    Complex s(1, 1);
    Complex d(0, 1);

    // Experiment
    s = s + d;

    // Assert results
    assert(s.getRealPart() == 1 and s.getImaginaryPart() == 2);
}