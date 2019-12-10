//
// Created by atara on 9/23/19.
//

#include "Edge.h"
#include <set>
#include <iostream>


    template<typename T>
    Edge<T>::Edge(std::pair<T, T> edge) {
        //this->edge = edge;
        this->u = edge.first;
        this->v = edge.second;
    }

template<typename T>

    Edge<T>::Edge(T u, T v) {
        this->u = u;
        this->v = v;
    }

template<typename T>
    std::pair<T, T> Edge<T>::forwardEdge() {
        //return edge;
        return std::pair<T, T>(u, v);
    }

template<typename T>
    std::pair<T, T> Edge<T>::backwardEdge() {
        //std::pair<int, int> opp(edge.second, edge.second);
        //return opp;
        return std::pair<int, int>(v, u);
    }

template<typename T>
    bool Edge<T>::operator==(Edge *other) {
        bool same = other->forwardEdge() == this->forwardEdge();
        bool opp = other->forwardEdge() == this->backwardEdge();
        return same || opp;
    }