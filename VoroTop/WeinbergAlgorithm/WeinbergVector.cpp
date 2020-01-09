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

/**
 * prepares for the recusrive part -
 * @param edge - the inital edge (u,v)
 * @param u - the vertex u of edge (u,v)
 * @param v - the vertex v of edge (u,v)
 */
template <typename T>
void WeinbergVector<T>::initialize(WeinbergEdge<int> *edge, int u, int v) {
    reset();
    edge->updateStatus();
    vertices[u]->old = true;
    vertices[u]->getWeinNum(&i);
    vertices[v]->getWeinNum(&i);
}


/**
 * runs the Weinberg algorithm on the first edge so that
 * it can compare following Weinberg codes to it.
 */
template <typename T>
void WeinbergVector<T>::getFirstWeinVec(){
    int u,v;
    WeinbergEdge<int>* e = edges[0];
    u = e->get_u();
    v = e->get_v();
    canonicalVector->addToVector(vertices[u]->getWeinNum(&i));
    canonicalVector->addToVector(vertices[v]->getWeinNum(&i));

    initialize(e, u, v);
    WeinbergAlgorithm<int>* algorithm = new WeinbergAlgorithm<int>(0, vertices, true, canonicalVector);
    algorithm->recursiveCal(vertices[v], e);
    delete(algorithm);
}

template <typename T>
void WeinbergVector<T>::calculate() {
    int u,v,iter;
    getFirstWeinVec();
    bool dir = 0;

    for(int j = 0; j < 2; j++){
        for(WeinbergEdge<int>* first : edges){
            for(iter = 0; iter < 2; iter++){
                if(iter == 1){
                    u = first->backwardEdge().first;
                    v = first->backwardEdge().second;
                }
                else{
                    u = first->forwardEdge().first;
                    v = first->forwardEdge().second;
                }
                initialize(first, u,v);
                WeinbergAlgorithm<int>* algorithm = new WeinbergAlgorithm<int>(dir, vertices, false, canonicalVector);
                algorithm->recursiveCal(vertices[v], first);
                delete(algorithm);
            }
        }
        dir = 1;
    }
}


template <typename T>
void WeinbergVector<T>::reset() {
    for(WeinbergEdge<int >* e : edges){
        e->reset();
    }
    for(WeinbergVertex<int>* v : vertices){
        v->reset();
    }
    this->i = 0;
    canonicalVector->resetIndex();
}


template<typename T>
CanonicalVector* WeinbergVector<T>::getCanonicalVector() {
    return canonicalVector;
}

template<typename T>
WeinbergVector<T>::~WeinbergVector() {
    delete canonicalVector;

}
template class WeinbergVector<int>;
