//
// Created by atara on 9/23/19.
//

#include <iostream>
#include "Vertex.h"

template<typename T>
bool Vertex<T>::operator()(const Vertex<T> &obj) const {
    return obj.data == data;
}

template<typename T>
bool Vertex<T>::operator==(const Vertex<T> &other) {
    return this->data == other.data;
}


template class Vertex<int>;
