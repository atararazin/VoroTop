//
// Created by atara on 11/4/19.
//

#ifndef VOROTOP_WEINBERGVERTEX_H
#define VOROTOP_WEINBERGVERTEX_H


#include "../Graph/Vertex.h"
#include "WeinbergEdge.h"

class WeinbergVertex : public Vertex {
private:
    int weinNum = -1;
    vector<WeinbergEdge*> listOfEdges;

public:
    int data;
    WeinbergVertex(int data);
    vector<WeinbergEdge*> getEdges();
    void addEdge(WeinbergEdge* e);
    bool old = false;
    int getWeinNum(int* i);
    WeinbergEdge* getRightMostNeighbor(WeinbergEdge* cameFrom);
    WeinbergEdge* getLeftMostNeighbor(WeinbergEdge* cameFrom);
    void reset();
};


#endif //VOROTOP_WEINBERGVERTEX_H
