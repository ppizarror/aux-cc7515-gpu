//
// Created by Pablo on 05-08-2019.
//

#include <cassert>
#include <iostream>
#include "punto.h"

int main() {
    auto *p1 = new Punto<int>(1, 2);
    assert(p1->get_x() == 1);
    std::cout << p1->to_string() << std::endl;
    return 0;
}