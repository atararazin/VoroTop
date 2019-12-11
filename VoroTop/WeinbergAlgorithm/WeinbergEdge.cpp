//
// Created by atara on 11/17/19.
//

#include "WeinbergEdge.h"

template<typename T>
void WeinbergEdge<T>::updateStatus() {
    if(this->status == NOTVISITED){
        this->status = NEW;
    }
    else{
        this->status = OLD;
    }
}

template<typename T>
int WeinbergEdge<T>::getStatus() {
    return this->status;
}

template<typename T>
void WeinbergEdge<T>::reset() {
    this->status = NOTVISITED;
}

template<typename T>
std::pair<T,T> WeinbergEdge<T>::getDirectedEdge(int v) {
    if(v == this->v){
        return this->forwardEdge();
    }
    else{
        return this->backwardEdge();
    }
}

template class WeinbergEdge<int>;
