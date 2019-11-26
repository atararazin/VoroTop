//
// Created by atara on 9/19/19.
//

#include "WeinbergVector.h"
#include "WeinbergEdge.h"
#include <iostream>

int index = 0;
bool first = true;
bool foundSmaller = false;


WeinbergVector::WeinbergVector(WeinbergGraph *g) {
    this->graph = g;
    this->vertices = g->vertices;
    this->edges = g->edges;
}

void WeinbergVector::initialize(WeinbergEdge *edge, int u, int v) {
    reset();
    /*for printing only*/
    cout << "edge:";
    edge->print();
    printf("");

    edge->updateStatus();
    vertices[u]->old = true;
    vertices[u]->getWeinNum(&i);
    vertices[v]->getWeinNum(&i);
}

void WeinbergVector::calculate() {
    int u,v,iter;
    Direction d = Right;
    WeinbergEdge* e = edges[0];
    u = e->getEdge().first;
    v = e->getEdge().second;
    this->canonicalVector.push_back(vertices[u]->getWeinNum(&i));
    this->canonicalVector.push_back(vertices[v]->getWeinNum(&i));
    initialize(e, u, v);
    this->recursiveCal(vertices[v], e);
    first = false;
    reset();

    for(int j = 0; j < 2; j++){
        updateDirection(d);
        for(WeinbergEdge* first : edges){
            for(iter = 0; iter < 2; iter++){
                if(iter == 1){
                    u = first->getOppEdge().first;
                    v = first->getOppEdge().second;
                }
                else{
                    u = first->getEdge().first;
                    v = first->getEdge().second;
                }
                initialize(first, u,v);
                this->recursiveCal(vertices[v], first);
            }
        }
        d = Left;
    }

    /*for printing only*/
    printf("weinberg code:");
       for(int i : canonicalVector){
           cout << i << ",";
       }
       printf("\n");
}


void WeinbergVector::recursiveCal(WeinbergVertex* node, WeinbergEdge* cameFrom) {
   if(getNeighbor(cameFrom,node) == NULL){
        return;
    }

    WeinbergEdge* edge;
    if(!node->old){
        node->old = true;
        WeinbergEdge* b = getNeighbor(cameFrom, node);
        edge = b;
    }
    else{
        if(cameFrom->getStatus() == WeinbergEdge::NEW){
            edge = cameFrom;
        }
        else{
            WeinbergEdge* b = getNeighbor(cameFrom, node);
            edge = b;
        }
    }

    edge->updateStatus();
    pair<int,int> directedEdge = edge->getDirectedEdge(node->data);
    WeinbergVertex* vertex = vertices[directedEdge.second];
    int code = vertices[directedEdge.second]->getWeinNum(&i);

    if(!first){
        if (!foundSmaller) {
                int res = compareToCode(code);
                if (res == 0) {
                } else if (res > 0) {
                    return;
                }
                else{//res < 0
                    foundSmaller = true;
                    this->canonicalVector[index - 1] = code;
                }
            }
        else{
            this->canonicalVector[index - 1] = code;
        }
        index++;
    }
    else{
        this->canonicalVector.push_back(code);
    }
    recursiveCal(vertex, edge);
}

void WeinbergVector::reset() {
    for(WeinbergEdge* e : edges){
        e->reset();
    }
    for(WeinbergVertex* v : vertices){
        v->reset();
    }
    this->i = 0;
    index = 3;
    foundSmaller = false;
}


void WeinbergVector::updateDirection(Direction d) {
    if(d == Right){
        direction = Right;
    }
    else{//d == Left
        direction = Left;
    }
}

WeinbergEdge* WeinbergVector::getNeighbor(WeinbergEdge *e, WeinbergVertex *v) {
    if(direction == Right){
        right(e,v);
    }
    else{
        left(e,v);
    }
}

WeinbergEdge* WeinbergVector::right(WeinbergEdge *e, WeinbergVertex* v) {
    return v->getRightMostNeighbor(e);
}

WeinbergEdge* WeinbergVector::left(WeinbergEdge *e, WeinbergVertex* v) {
    return v->getLeftMostNeighbor(e);
}

int WeinbergVector::compareToCode(int i) {
    if(i > canonicalVector[index - 1]){
        return 1;
    }
    else if(i == canonicalVector[index - 1]){
        return 0;
    }
    else{
        return -1;
    }
}