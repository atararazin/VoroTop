//
// Created by atara on 9/23/19.
//

#include "Edge.h"
#include <set>
#include <iostream>


template<typename T>
Edge<T>::Edge(std::pair<T, T> edge) {
    this->u = edge.first;
    this->v = edge.second;
    this->forward = std::pair<T,T>(u,v);
    this->backwards = std::pair<T,T>(v,u);
}

template<typename T>
Edge<T>::Edge(T u, T v) {
    this->u = u;
    this->v = v;
    this->forward = std::pair<T,T>(u,v);
    this->backwards = std::pair<T,T>(v,u);
}

template<typename T>
std::pair<T, T> Edge<T>::forwardEdge() {
    return forward;
}

template<typename T>
std::pair<T, T> Edge<T>::backwardEdge() {
    return backwards;
}

template<typename T>
bool Edge<T>::operator== (Edge const &obj){
    return obj.forward == forward || obj.backwards == forward;
}

template class Edge<int>;
