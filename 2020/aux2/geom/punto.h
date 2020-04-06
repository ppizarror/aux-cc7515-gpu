//
// Created by Pablo on 05-08-2019.
//

#ifndef CC7515_AUX_1_PUNTO_H
#define CC7515_AUX_1_PUNTO_H

// Importamos librerías
#include <iostream>

template<class T>
class Punto {
private:
    T coord[2]; // Lista de dos puntos
public:
    Punto(T x, T y); // Constructor

    ~Punto(); // Destructor

    // Retorna el punto en forma de String
    std::string to_string() const;

    T get_x() const; // Retorna X

    T get_y() const;  // Retorna Y

    // Suma dos puntos y retorna un tercero
    Punto<T> operator+(const Punto<T> &p) const;

    // Suma un punto a sí mismo
    Punto<T> &operator+=(const Punto<T> &p);
};

template<class T>
Punto<T>::Punto(T x, T y) {
    this->coord[0] = x;
    this->coord[1] = y;
}

template<class T>
Punto<T>::~Punto() {
    // A priori no tomamos memoria
}

template<class T>
std::string Punto<T>::to_string() const {
    std::string s = "(" + std::to_string(this->coord[0]) + ", " + std::to_string(this->coord[1]) + ")";
    return s;
}

template<class T>
Punto<T> Punto<T>::operator+(const Punto<T> &p) const {
    return Punto<T>(T(this->get_x() + p.get_x()), T(this->get_y() + p.get_y()));
}

template<class T>
T Punto<T>::get_x() const {
    return this->coord[0];
}

template<class T>
T Punto<T>::get_y() const {
    return this->coord[1];
}

template<class T>
Punto<T> &Punto<T>::operator+=(const Punto<T> &p) {
    this->coord[0] += p.get_x();
    this->coord[1] += p.get_y();
    return *this;
}

#endif //CC7515_AUX_1_PUNTO_H