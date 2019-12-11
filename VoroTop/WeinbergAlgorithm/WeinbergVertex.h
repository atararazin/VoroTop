//
// Created by atara on 11/4/19.
//

#ifndef VOROTOP_WEINBERGVERTEX_H
#define VOROTOP_WEINBERGVERTEX_H


#include "../Graph/Vertex.h"
#include "WeinbergEdge.h"
template <typename T>
class WeinbergVertex : public Vertex<T> {
private:
    int weinNum = -1;
    vector<WeinbergEdge<int>*> listOfEdges;

public:
    int data;
    WeinbergVertex(T data) : Vertex<int>(data){};
    vector<WeinbergEdge<int>*> getEdges();
    void addEdge(WeinbergEdge<int>* e);
    bool old = false;
    int getWeinNum(int* i);
    WeinbergEdge<int>* getRightMostNeighbor(WeinbergEdge<int>* cameFrom);
    WeinbergEdge<int>* getLeftMostNeighbor(WeinbergEdge<int>* cameFrom);
    void reset();
};


#endif //VOROTOP_WEINBERGVERTEX_H
