//
// Created by atara on 11/4/19.
//

#include <iostream>
#include<vector>
#include "WeinbergVertex.h"
#include "WeinbergEdge.h"

/*
template <typename T>
int WeinbergVertex<T>::getWeinNum(int* i) {
    if(this->weinNum == -1){
        this->weinNum = *i + 1;
        *i+=1;
    }
    return this->weinNum;
}*/

/*
template<typename T>
vector<WeinbergEdge<T>*> WeinbergVertex<T>::getEdges() {
    return listOfEdges;
}*/

template<typename T>
void WeinbergVertex<T>::addEdge(WeinbergEdge<T> *e) {
    listOfEdges.push_back(e);
}

template<typename T>
WeinbergEdge<T>* WeinbergVertex<T>::getRightMostNeighbor(WeinbergEdge<T>* cameFrom) {
    int n = this->listOfEdges.size();
    int indexOfCameFrom = 0;
    while(listOfEdges[indexOfCameFrom] != cameFrom){
        indexOfCameFrom++;
    }

    int i = (indexOfCameFrom + 1) % n;
    while(listOfEdges[i] != cameFrom){
        if(listOfEdges[i]->getStatus() != WeinbergEdge<T>::OLD){
            return listOfEdges[i];
        }
        i = (i +1) % n;
    }
    return NULL;
}

template<typename T>
WeinbergEdge<T>* WeinbergVertex<T>::getLeftMostNeighbor(WeinbergEdge<T>* cameFrom) {
    int n = this->listOfEdges.size();
    for(int i = 0; i < n; i++) {
        if (this->listOfEdges[i] == cameFrom) {
           // if (this->listOfEdges[i]->forwardEdge() == cameFrom->forwardEdge()) {
            i = (n + (i - 1 % n)) % n;
            while(this->listOfEdges[i % n] != cameFrom){
                //while(this->listOfEdges[i % n]->forwardEdge() != cameFrom->forwardEdge()){
                if(this->listOfEdges[i % n]->getStatus() != WeinbergEdge<T >::OLD){
                    return this->listOfEdges[i % n];
                }
                i = (n + (i - 1 % n)) % n;
            }
        }
    }
    return NULL;
}

/*
template<typename T>
void WeinbergVertex<T>::reset() {
    this->old = false;
    this->weinNum = -1;
}
*/


template class WeinbergVertex<int>;
