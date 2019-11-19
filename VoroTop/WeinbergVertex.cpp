//
// Created by atara on 11/4/19.
//

#include <iostream>
#include "WeinbergVertex.h"
#include "WeinbergEdge.h"

WeinbergVertex::WeinbergVertex(int data) : Vertex(data){
    this->data = data;
}

int WeinbergVertex::getWeinNum(int* i) {
    if(this->weinNum == -1){
        this->weinNum = *i+1;
        i++;
    }
    return this->weinNum;
}

vector<WeinbergEdge*> WeinbergVertex::getEdges() {
    return this->listOfEdges;
}

void WeinbergVertex::addEdge(WeinbergEdge *e) {
    this->listOfEdges.push_back(e);
}

WeinbergEdge* WeinbergVertex::getRightMostNeighbor(WeinbergEdge* cameFrom) {
    int n = listOfEdges.size();
    for(int i = 0; i < n; i++) {
        if (listOfEdges[i]->edge == cameFrom->edge) {
            i++;
            while(listOfEdges[i % n]->edge != cameFrom->edge){
                if(listOfEdges[i % n]->getStatus() != WeinbergEdge::OLD){
                    return listOfEdges[i % n];
                }
                i++;
            }
        }
    }
    return NULL;
}