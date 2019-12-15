//
// Created by atara on 11/17/19.
//

#include "WeinbergEdge.h"

/**
 * increases status by one. Meaning, if previously, the status was NOTVISITED, we'll update it
 * to NEW. If it previously was NEW, update it to OLD. There is no other possible scenario.
 */
template<typename T>
void WeinbergEdge<T>::updateStatus() {
    if(this->status == NOTVISITED){
        this->status = NEW;
    }
    else if(this->status == NEW){
        this->status = OLD;
    }
}

template<typename T>
int WeinbergEdge<T>::getStatus() {
    return this->status;
}

/**
 * Reset status to be NOTVISITED so we can iterate over the edge again.
 */
template<typename T>
void WeinbergEdge<T>::reset() {
    this->status = NOTVISITED;
}

/**
 * given the first value of the edge, return the edge as (u,v) or (v,u)
 * @param u
 * @return
 */
template<typename T>
std::pair<T,T> WeinbergEdge<T>::getDirectedEdge(int u) {
    if(u == this->u){
        return this->forwardEdge();
    }
    else{
        return this->backwardEdge();
    }
}

template class WeinbergEdge<int>;
