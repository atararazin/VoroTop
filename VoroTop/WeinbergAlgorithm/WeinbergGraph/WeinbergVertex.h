//
// Created by atara on 11/4/19.
//

#ifndef VOROTOP_WEINBERGVERTEX_H
#define VOROTOP_WEINBERGVERTEX_H


#include "../../Graph/Vertex.h"
#include "WeinbergEdge.h"
template <typename T>
class WeinbergVertex : public Vertex<T> {

public:
    WeinbergVertex(T data) : Vertex<T>(data){};
    void addEdge(WeinbergEdge<T>* e);
    WeinbergEdge<T>* getRightMostNeighbor(WeinbergEdge<T>* cameFrom);
    WeinbergEdge<T>* getLeftMostNeighbor(WeinbergEdge<T>* cameFrom);
private:
    vector<WeinbergEdge<T>*> listOfEdges;
    int n = 0;

};


#endif //VOROTOP_WEINBERGVERTEX_H
