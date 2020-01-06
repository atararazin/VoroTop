//
// Created by atara on 9/19/19.
//

#include "WeinbergVector.h"
#include "WeinbergGraph/WeinbergEdge.h"
#include <iostream>

/**
 * constructor. Initializes the graph, vertices and edges all from the graph it gets.
 * @param g - the graph we're calculating the Weinberg code on
 * @return
 */
template <typename T>
WeinbergVector<T>::WeinbergVector() {
    canonicalVector = new CanonicalVector();
    direction = new Direction();
}

template <typename T>
void WeinbergVector<T>::setGraph(WeinbergGraph<T> *g) {
    this->graph = g;
    this->vertices = g->vertices;
    this->edges = g->edges;
    this->canonicalVector->clear();
    i = 0;
    first = true;

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
    this->recursiveCal(vertices[v], e);
    first = false;
}

template <typename T>
void WeinbergVector<T>::calculate() {
    int u,v,iter;
    direction->setDirection("Right");
    getFirstWeinVec();

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
                this->recursiveCal(vertices[v], first);
            }
        }
        direction->setDirection("Left");
    }
}

template <typename T>
void WeinbergVector<T>::recursiveCal(WeinbergVertex<int>* node, WeinbergEdge<int>* cameFrom) {

    //base condition - if we've reached a node that we've already visited all neighbors
   if(getNeighbor(cameFrom,node) == NULL){
        return;
    }

    WeinbergEdge<int>* edge;

    //if our node has not yet been visited
    if(!node->old){
        node->old = true;
        WeinbergEdge<int>* b = getNeighbor(cameFrom, node);
        edge = b;
    }
    else{//if the node is old, already visited
        //if we haven't yet visited in the opposite direction, visit the opposite direction
        if(cameFrom->getStatus() == WeinbergEdge<int >::NEW){
            edge = cameFrom;
        }
        else{//if we've already visited both directions
            WeinbergEdge<int >* b = getNeighbor(cameFrom, node);
            edge = b;
        }
    }

    edge->updateStatus();
    pair<int,int> directedEdge = edge->getDirectedEdge(node->data);
    WeinbergVertex<int>* vertex = vertices[directedEdge.second];
    int code = vertices[directedEdge.second]->getWeinNum(&i);


    if(first){
        canonicalVector->addToVector(code);
        return recursiveCal(vertex, edge);
    }

    if (!foundSmaller) {
        //compare our vertices Weinberg code to the canonical vector
        string res = canonicalVector->compareToCode(code);

        //if our code is bigger then stop calculating the Weinberg code on this edge
        if (res == "bigger") {
            return;
        }
            //if it's smaller, update the canonical vector with our Weinberg values
        else if(res == "smaller"){
            foundSmaller = true;
            canonicalVector->changeCurrValue(code);
        }
    }
    else{
        canonicalVector->changeCurrValue(code);
    }
    canonicalVector->incrementIndex();
    //checkBiggerOrSmaller(code);
    recursiveCal(vertex, edge);
}

template<typename T>
void WeinbergVector<T>::checkBiggerOrSmaller(int code) {
    if (!foundSmaller) {
        //compare our vertices Weinberg code to the canonical vector
        string res = canonicalVector->compareToCode(code);

        //if our code is bigger then stop calculating the Weinberg code on this edge
        if (res == "bigger") {
            return;
        }
            //if it's smaller, update the canonical vector with our Weinberg values
        else if(res == "smaller"){
            foundSmaller = true;
            canonicalVector->changeCurrValue(code);
        }
    }
    else{
        canonicalVector->changeCurrValue(code);
    }
    canonicalVector->incrementIndex();
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
    foundSmaller = false;
}

/**
 * get right or left most neighbor, depending on our current direction
 * @param e - the edge we came from
 * @param v - the vertex we are coming from
 * @return the right or left most neighbor
 */
template <typename T>
WeinbergEdge<int>* WeinbergVector<T>::getNeighbor(WeinbergEdge<int> *e, WeinbergVertex<int> *v) {
    if(direction->getDirection() == 0){
        return v->getRightMostNeighbor(e);
    }
    else{
        return v->getLeftMostNeighbor(e);
    }
}

template<typename T>
CanonicalVector* WeinbergVector<T>::getCanonicalVector() {
    return canonicalVector;
}

template<typename T>
WeinbergVector<T>::~WeinbergVector() {
    delete canonicalVector;
    delete(direction);

}
template class WeinbergVector<int>;
