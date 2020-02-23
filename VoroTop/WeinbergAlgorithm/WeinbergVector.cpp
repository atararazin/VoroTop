//
// Created by atara on 9/19/19.
//

#include "WeinbergVector.h"
#include "WeinbergGraph/WeinbergEdge.h"
#include "WeinbergAlgorithm.h"
#include <iostream>

/**
 * constructor. Initializes the graph, vertices and edges all from the graph it gets.
 * @param g - the graph we're calculating the Weinberg code on
 * @return
 */
template <typename T>
WeinbergVector<T>::WeinbergVector() {
    canonicalVector = new CanonicalVector();
}

template <typename T>
WeinbergVector<T>::WeinbergVector(WeinbergGraph<T> *g) {
    this->graph = g;
    this->vertices = g->vertices;
    this->edges = g->edges;
    canonicalVector = new CanonicalVector();
}



template <typename T>
void WeinbergVector<T>::calculate() {
    int u,v;
    bool firstIter = true;
    bool firstFlag;


    for(int dir = 0; dir < 2; dir++){
        for(WeinbergEdge<int>* first : edges){
            for(int iter = 0; iter < 2; iter++){
                if(iter == 0){
                    u = first->get_u();
                    v = first->get_v();
                }
                else{//backwards (v,u)
                    u = first->backwardEdge().first;
                    v = first->backwardEdge().second;
                }
                if(firstIter){
                    firstFlag = true;
                    firstIter = false;
                }
                else{
                    firstFlag = false;
                }
                reset();
                WeinbergAlgorithm<int>* algorithm = new WeinbergAlgorithm<int>(u, v,dir, vertices, firstFlag, canonicalVector);
                algorithm->recursiveCal(vertices[v], first);
                delete(algorithm);
            }
        }
    }
}


template <typename T>
void WeinbergVector<T>::reset() {
    for(WeinbergEdge<T>* edge : edges){
        edge->reset();
    }
    canonicalVector->resetIndex();
}

template<typename T>
vector<int>& WeinbergVector<T>::getCanonicalVector() {
    return canonicalVector->getVector();
}

template<typename T>
WeinbergVector<T>::~WeinbergVector() {
    delete canonicalVector;

}
template class WeinbergVector<int>;
