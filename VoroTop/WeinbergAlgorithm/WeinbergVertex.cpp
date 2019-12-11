//
// Created by atara on 11/4/19.
//

#include <iostream>
#include "WeinbergVertex.h"
#include "WeinbergEdge.h"

template <typename T>
int WeinbergVertex<T>::getWeinNum(int* i) {
    if(this->weinNum == -1){
        this->weinNum = *i + 1;
        *i+=1;
    }
    return this->weinNum;
}

template<typename T>
vector<WeinbergEdge<int>*> WeinbergVertex<T>::getEdges() {
    return this->listOfEdges;
}

template<typename T>
void WeinbergVertex<T>::addEdge(WeinbergEdge<int> *e) {
    this->listOfEdges.push_back(e);
}

template<typename T>
WeinbergEdge<int>* WeinbergVertex<T>::getRightMostNeighbor(WeinbergEdge<int >* cameFrom) {
    int n = listOfEdges.size();
    for(int i = 0; i < n; i++) {
        if (listOfEdges[i]->forwardEdge() == cameFrom->forwardEdge()) {
            i++;
            while(listOfEdges[i % n]->forwardEdge() != cameFrom->forwardEdge()){
                if(listOfEdges[i % n]->getStatus() != WeinbergEdge<int>::OLD){
                    return listOfEdges[i % n];
                }
                i++;
            }
        }
    }
    return NULL;
}

template<typename T>
WeinbergEdge<int >* WeinbergVertex<T>::getLeftMostNeighbor(WeinbergEdge<int>* cameFrom) {
    int n = listOfEdges.size();
    for(int i = 0; i < n; i++) {
        if (listOfEdges[i]->forwardEdge() == cameFrom->forwardEdge()) {
            //if (listOfEdges[i]->edge == cameFrom->edge) {
            i--;
            if(i == -1)
                i = n-1;
            while(listOfEdges[i % n]->forwardEdge() != cameFrom->forwardEdge()){
           // while(listOfEdges[i % n]->edge != cameFrom->edge){
                if(listOfEdges[i % n]->getStatus() != WeinbergEdge<int >::OLD){
                    return listOfEdges[i % n];
                }
                i--;
                if(i == -1)
                    i = n-1;
            }
        }
    }
    return NULL;
}

template<typename T>
void WeinbergVertex<T>::reset() {
    this->old = false;
    this->weinNum = -1;
}



template class WeinbergVertex<int>;
