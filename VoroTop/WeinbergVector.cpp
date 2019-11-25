//
// Created by atara on 9/19/19.
//

#include "WeinbergVector.h"
#include "WeinbergEdge.h"
#include <iostream>

int getSecond(WeinbergVertex* v, WeinbergEdge* curr);
int index = 0;


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
    this->weinbergCode.push_back(vertices[u]->getWeinNum(&i));
    this->weinbergCode.push_back(vertices[v]->getWeinNum(&i));
}

void WeinbergVector::calculate() {
    int u,v,iter;
    cout << edges.size() << endl;
    updateDirection(Right);
    bool isFirst = true;

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

    //for loop for left
    printf("LEFT:\n");
    updateDirection(Left);
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

}


void WeinbergVector::recursiveCal(WeinbergVertex* node, WeinbergEdge* cameFrom) {
    //if(node->getRightMostNeighbor(cameFrom) == NULL){
    if(getNeighbor(cameFrom,node) == NULL){
        /*for printing only*/
        printf("weinberg code:");
        for(int i : weinbergCode){
            cout << i << ",";
        }
        printf("\n");
        printf("\n");
        //first = false;
        return;
    }

    int code;
    WeinbergVertex* vertex;
    WeinbergEdge* edge;
    if(!node->old){
        node->old = true;
        WeinbergEdge* b = getNeighbor(cameFrom, node);
        int sec = getSecond(node, b);
        code = vertices[sec]->getWeinNum(&i);
        b->updateStatus();
        edge = b;
        vertex = vertices[sec];
    }
    else{
        if(cameFrom->getStatus() == WeinbergEdge::NEW){
            cameFrom->updateStatus();
            int sec = getSecond(node, cameFrom);
            if(cameFrom->getEdge().second == sec){
                code = vertices[cameFrom->getEdge().second]->getWeinNum(&i);
            }
            else{
                code = vertices[cameFrom->getEdge().first]->getWeinNum(&i);
            }
            int u;
            if(cameFrom->getEdge().second == sec){
                u = cameFrom->getEdge().second;
            }
            else{
                u = cameFrom->getEdge().first;
            }
            vertex = vertices[u];
            edge = cameFrom;
        }
        else{
            //WeinbergEdge* b = node->getRightMostNeighbor(cameFrom);
            WeinbergEdge* b = getNeighbor(cameFrom, node);
            int sec = getSecond(node,b);
            if(b->getEdge().second == sec){
                code = vertices[b->getEdge().second]->getWeinNum(&i);
            }
            else{
                code = vertices[b->getEdge().first]->getWeinNum(&i);

            }
            b->updateStatus();
            int v;
            if(b->getEdge().second == sec){
                v = b->getEdge().second;
            }
            else{
                v = b->getEdge().first;
            }
            edge = b;
            vertex = vertices[v];
        }
    }

    /*if(first == true){
        printf("first");
        this->weinbergCode.push_back(code);
        for(int i : weinbergCode){
            cout << i <<endl;
        }

    }
    int res = compareToCode(code);
    if(res < 0){
        printf("smaller");
        this->weinbergCode.push_back(code);
    }
    else if(res > 0){
        return;
    }
    index++;*/
    this->weinbergCode.push_back(code);
    recursiveCal(vertex, edge);
}


int getSecond(WeinbergVertex* v, WeinbergEdge* curr){
    int second;
    if(v->data == curr->edge.first ){
        second = curr->edge.second;
    }
    else{
        second = curr->edge.first;
    }
    return second;
}

void WeinbergVector::reset() {
    for(WeinbergEdge* e : edges){
        e->reset();
    }
    for(WeinbergVertex* v : vertices){
        v->reset();
    }
    weinbergCode.clear();
    this->i = 0;
    index = 0;

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
    if(i > weinbergCode[index]){
        return 1;
    }
    else if(i == weinbergCode[index]){
        return 0;
    }
    else{
        return -1;
    }
}