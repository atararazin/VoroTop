//
// Created by atara on 11/17/19.
//

#include "WeinbergEdge.h"

/*WeinbergEdge::WeinbergEdge(std::pair<int, int> edge) : Edge(edge){
    this->edge = edge;
}*/

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
std::pair<int,int> WeinbergEdge<T>::getDirectedEdge(int v) {
    if(v == this->v){
        return forwardEdge();
    }
    else{
        return this->backwardEdge();
    }
}
