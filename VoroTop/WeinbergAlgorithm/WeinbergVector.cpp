//
// Created by atara on 9/19/19.
//

#include "WeinbergVector.h"
#include <iostream>
#include "WeinbergAlgorithm.h"
#include "../ThreadPool.h"

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
 * the algorithm runs in each direction twice - left and right.
 * then it runs on each edge and in both directions.
 */
template <typename T>
void WeinbergVector<T>::calculate() {
    int u,v;
    WeinbergAlgorithm<int>* algorithm = new WeinbergAlgorithm<int>(vertices, canonicalVector);
    for(int dir = 0; dir < 2; dir++){
        algorithm->updateDir(dir);
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

                algorithm->init(u,v);
                algorithm->recursiveCal(vertices[v], first);
                reset();

            }
        }
    }
    delete(algorithm);
}


/**
 * resets the edge's status.
 * resets the canonical vector's index
 */
template <typename T>
void WeinbergVector<T>::reset() {
    for(WeinbergEdge<T>* edge : edges){
        edge->reset();
    }
    canonicalVector->resetIndex();
}

/**
 * puts the caninical vector in the string form.
 * @return
 */
template<typename T>
string WeinbergVector<T>::getString() {
    string str = "(";
    for(int i : canonicalVector->getVector()){
        str += to_string(i);
        str += ",";
    }
    str.pop_back();
    str += ")\n";
    return str;
}



template<typename T>
WeinbergVector<T>::~WeinbergVector() {
    delete canonicalVector;

}
template class WeinbergVector<int>;
