//
// Created by atara on 9/23/19.
//

#include <iostream>
#include "Vertex.h"



//template<typename T>
/*vector<Edge<T>*> Vertex<T>::getEdges() {
    return this->listOfEdges;
}

template<typename T>
void Vertex<T>::addEdge(Edge<T> *e) {
    this->listOfEdges.push_back(e);
}*/

template<typename T>
bool Vertex<T>::operator()(const Vertex<T> &obj) const {
    return obj.data == data;
}

template<typename T>
bool Vertex<T>::operator==(const Vertex<T> &other) {
    return data == other.data;
}

template class Vertex<int>;
