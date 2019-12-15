//
// Created by atara on 9/23/19.
//

#include <sstream>
#include "Graph.h"

template<typename T>
void Graph<T>::create(string faces) {
    this->getFaces(faces);
    this->getVertices();
    this->getEdges();
}

template class Graph<int>;




