//
// Created by atara on 11/4/19.
//

#ifndef VOROTOP_WEINBERGVERTEX_H
#define VOROTOP_WEINBERGVERTEX_H


#include "../../Graph/Vertex.h"
#include "WeinbergEdge.h"
template <typename T>
class WeinbergVertex : public Vertex<T> {
private:
    int weinNum = -1;
    vector<WeinbergEdge<T>*> listOfEdges;

public:
    WeinbergVertex(T data) : Vertex<T>(data){};
    vector<WeinbergEdge<T>*> getEdges();
    void addEdge(WeinbergEdge<T>* e);
    bool old = false;
    int getWeinNum(int* i);
    WeinbergEdge<T>* getRightMostNeighbor(WeinbergEdge<T>* cameFrom);
    WeinbergEdge<T>* getLeftMostNeighbor(WeinbergEdge<T>* cameFrom);
    void reset();
};


#endif //VOROTOP_WEINBERGVERTEX_H
