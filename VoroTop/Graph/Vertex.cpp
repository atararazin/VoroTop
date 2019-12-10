//
// Created by atara on 9/23/19.
//

#include <iostream>
#include "Vertex.h"


bool Vertex::operator()(const Vertex &obj) const {
    return obj.data == data;
}


bool Vertex::operator==(const Vertex &other) {
    return this->data == other.data;
}