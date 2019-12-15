//
// Created by atara on 9/23/19.
//

#include "Edge.h"
#include <set>
#include <iostream>

template<typename T>
Edge<T>::Edge(T u, T v) {
    this->u = u;
    this->v = v;
    this->forward = std::pair<T,T>(u,v);
    this->backwards = std::pair<T,T>(v,u);
}

template<typename T>
T Edge<T>::get_u() {
    return this->u;
}


template<typename T>
T Edge<T>::get_v() {
    return this->v;
}


/**
 * edge in the format (u,v)
 * @return
 */
template<typename T>
std::pair<T, T> Edge<T>::forwardEdge() {
    return forward;
}

/**
 * edge in the format (v,u)
 * @return
 */
template<typename T>
std::pair<T, T> Edge<T>::backwardEdge() {
    return backwards;
}

/**
 * two edges (u,v) and (w,x) are equal if (u,v) = (w,x) or (v,u) = (w,x)
 * @param obj
 * @return
 */
template<typename T>
bool Edge<T>::operator== (Edge const &obj){
    return obj.forward == forward || obj.backwards == forward;
}

template class Edge<int>;
