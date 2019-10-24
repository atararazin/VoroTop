//
// Created by atara on 9/23/19.
//

#include <iostream>
#include "Vertex.h"

Vertex::Vertex(int data) {
    this->data = data;
}

void Vertex::print() {
    cout << this->data << endl;
}