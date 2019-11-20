//
// Created by atara on 11/4/19.
//

#include <iostream>
#include "WeinbergVertex.h"
#include "WeinbergEdge.h"

WeinbergVertex::WeinbergVertex(int data) : Vertex(data){
    this->data = data;
}

int WeinbergVertex::getWeinNum(int* i) {
    if(this->weinNum == -1){
        this->weinNum = *i+1;
        i++;
    }
    return this->weinNum;
}

vector<WeinbergEdge*> WeinbergVertex::getEdges() {
    return this->listOfEdges;
}

void WeinbergVertex::addEdge(WeinbergEdge *e) {
    this->listOfEdges.push_back(e);
}

WeinbergEdge* WeinbergVertex::getRightMostNeighbor(WeinbergEdge* cameFrom) {
    printf("in weinberg");
    printf("");
    int n = listOfEdges.size();
    cout << n<<endl;
    cout<<this->data<<endl;
    for(int i = 0; i < n; i++) {
        cameFrom->print();
        bool b = listOfEdges[i]->edge == cameFrom->edge;
        listOfEdges[0]->print();
        listOfEdges[1]->print();
        listOfEdges[2]->print();

        if (listOfEdges[i]->edge == cameFrom->edge) {
            i++;
            printf("er");
            while(listOfEdges[i % n]->edge != cameFrom->edge){
                printf("jere");
                if(listOfEdges[i % n]->getStatus() != WeinbergEdge::OLD){
                    return listOfEdges[i % n];
                }
                i++;
            }
        }
    }
    return NULL;
}