//
// Created by atara on 11/4/19.
//

#include "WeinbergVertex.h"


int WeinbergVertex::getWeinNum(int* i) {
    if(this->weinNum == -1){
        this->weinNum = *i+1;
        i++;
    }
    return this->weinNum;
}

Edge * WeinbergVertex::getRightMostNeighbor() {
    for(Edge* e : Vertex::getEdges()){
        if(e->getStatus() == e->NOTVISITED){
            return e;
        }
    }
    throw "something wrong with your algorithm!";
}