//
// Created by atara on 9/19/19.
//

#include "WeinbergVector.h"

void WeinbergVector::recursiveCal(Vertex node, Edge cameFrom, Edge original) {
    if(cameFrom.getEdge() == original.getEdge()){
        return;
    }

    if(!node.old){
        node.old = true;
        Edge b = node.getRightMostNeighbor();
        this->weinbergCode.push_back(b.second);
        b.updateStatus();
        recursiveCal(b.second, b, cameFrom);
    }
    else{
        if(cameFrom.getStatus()==cameFrom.NEW){
            cameFrom.updateStatus();
            this->weinbergCode.push_back(cameFrom.second);
            recursiveCal(cameFrom.first, cameFrom, original);
        }
        else{
            Edge b = node.getRightMostNeighbor();
            this->weinbergCode.push_back(b.second);
            b.updateStatus();
            recursiveCal(b.second, b, original);
        }
    }
}