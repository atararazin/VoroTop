//
// Created by atara on 9/19/19.
//

#include "WeinbergVector.h"
#include "WeinbergEdge.h"
#include <iostream>
#include <iterator>
#include <map>

map<int, int> vcodes;
int getSecond(WeinbergVertex* v, WeinbergEdge* curr);

WeinbergVector::WeinbergVector(WeinbergGraph *g) {
    this->graph = g;
}

void WeinbergVector::calculate() {
    printf("\n");
    printf("calculating");
    this->i = 0;
    for(Vertex* v : graph->vertices){
        vcodes.insert({v->data, -1});
    }

    WeinbergEdge* first = this->graph->edges[0];
    first->print();
    first->updateStatus();
    int u = first->getEdge().first;
    int v = first->getEdge().second;
    this->weinbergCode.push_back(this->getVCode(u));
    this->weinbergCode.push_back(this->getVCode(v));
    this->recursiveCal(graph->vertices[v], first);

}


int WeinbergVector::getVCode(int node) {
    if(vcodes[node] == -1){
        vcodes[node] = this->i + 1;
        this->i++;
    }
    return vcodes[node];
}

void WeinbergVector::recursiveCal(WeinbergVertex* node, WeinbergEdge* cameFrom) {
    printf("weinberg code:");
    for(int i : weinbergCode){
        cout << i <<endl;
    }
    printf("");
    if(node->getRightMostNeighbor(cameFrom) == NULL){
        return;
    }

    int code;
    WeinbergVertex* vertex;
    WeinbergEdge* edge;
    if(!node->old){
        node->old = true;
        WeinbergEdge* b = node->getRightMostNeighbor(cameFrom);
        printf("right:");
        b->print();
        int sec = getSecond(node, b);
        code = this->getVCode(sec);
        b->updateStatus();
        edge = b;
        vertex = graph->vertices[sec];
    }
    else{
        if(cameFrom->getStatus() == cameFrom->NEW){
            cameFrom->updateStatus();
            int sec = getSecond(node, cameFrom);
            if(cameFrom->getEdge().second == sec){
                code = this->getVCode(cameFrom->getEdge().second);
            }
            else{
                code = this->getVCode(cameFrom->getEdge().first);
            }
            int u;
            if(cameFrom->getEdge().second == sec){
                u = cameFrom->getEdge().second;
            }
            else{
                u = cameFrom->getEdge().first;
            }
            vertex = graph->vertices[u];
            edge = cameFrom;
        }
        else{
            WeinbergEdge* b = node->getRightMostNeighbor(cameFrom);
            int sec = getSecond(node,b);
            if(cameFrom->getEdge().second == sec){
                code = this->getVCode(cameFrom->getEdge().second);
            }
            else{
                code = this->getVCode(cameFrom->getEdge().first);
            }
            b->updateStatus();
            int v;
            if(cameFrom->getEdge().second == sec){
                v = cameFrom->getEdge().second;
            }
            else{
                v = cameFrom->getEdge().first;
            }
            edge = b;
            vertex = graph->vertices[v];
        }
    }
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