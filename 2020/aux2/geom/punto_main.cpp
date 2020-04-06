//
// Created by Pablo on 05-08-2019.
//

#include "punto.h"
#include <cassert>

#pragma clang diagnostic push
#pragma ide diagnostic ignored "hicpp-use-auto"

int main() {
    Punto<int> *p = new Punto<int>(1, 6);
    Punto<int> *p2 = new Punto<int>(-1, 0);
    auto p5 = *p + p2;
    Punto<double> *p4 = new Punto<double>(-1, 0);
    Punto<int> p3 = *p + *p2;
    assert(p5.get_y() == 6);
    assert(p->get_x() == 1);
    assert(p3.get_x() == 0);
    std::cout << p3.to_string() << std::endl;
    delete p;
    return 0;
}

#pragma clang diagnostic pop