//
// Created by atara on 11/4/19.
//

#include <iostream>
#include<vector>
#include "WeinbergVertex.h"
#include "WeinbergEdge.h"

template<typename T>
void WeinbergVertex<T>::addEdge(WeinbergEdge<T> *e) {
    listOfEdges.push_back(e);
    n++;
}

/**
 * gets the next neighbor who's status is not OLD. loops around using modulo.
 * @param cameFrom
 * @return
 */
template<typename T>
WeinbergEdge<T>* WeinbergVertex<T>::getRightMostNeighbor(WeinbergEdge<T>* cameFrom) {
    //get index of CameFrom
    int indexOfCameFrom = 0;
    while(listOfEdges[indexOfCameFrom] != cameFrom){
        indexOfCameFrom++;
    }

    //get the next edge's index
    int i = (indexOfCameFrom + 1) % n;
    //keep running until it gets back to cameFrom
    while(listOfEdges[i] != cameFrom){
        //if the edge's status is not OLD, then return it
        if(listOfEdges[i]->getStatus() != WeinbergEdge<T>::OLD){
            return listOfEdges[i];
        }
        //increases by 1
        i = (i +1) % n;
    }
    //Not a valid situation
    return NULL;
}

template<typename T>
WeinbergEdge<T>* WeinbergVertex<T>::getLeftMostNeighbor(WeinbergEdge<T>* cameFrom) {
    for(int i = 0; i < n; i++) {
        if (this->listOfEdges[i] == cameFrom) {
            i = (n + (i - 1 % n)) % n;
            while(this->listOfEdges[i % n] != cameFrom){
                if(this->listOfEdges[i % n]->getStatus() != WeinbergEdge<T >::OLD){
                    return this->listOfEdges[i % n];
                }
                i = (n + (i - 1 % n)) % n;
            }
        }
    }
    return NULL;
}


template class WeinbergVertex<int>;
