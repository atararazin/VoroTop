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
    printf("calculating\n");
    this->i = 0;
    for(Vertex* v : graph->vertices){
        vcodes.insert({v->data, -1});
    }
    for(WeinbergEdge* first : graph->edges){
        reset();
        cout << "edge:";
        first->print();
        printf("");
        first->updateStatus();
        int u = first->getOppEdge().first;
        int v = first->getOppEdge().second;
        graph->vertices[u]->old = true;
        this->weinbergCode.push_back(this->getVCode(u));
        this->weinbergCode.push_back(this->getVCode(v));
        this->recursiveCal(graph->vertices[v], first);
    }
    for(WeinbergEdge* first : graph->edges){
        reset();
        cout << "edge:";
        first->print();
        printf("");
        first->updateStatus();
        int u = first->getEdge().first;
        int v = first->getEdge().second;
        graph->vertices[u]->old = true;
        this->weinbergCode.push_back(this->getVCode(u));
        this->weinbergCode.push_back(this->getVCode(v));
        this->recursiveCal(graph->vertices[v], first);
    }
}


int WeinbergVector::getVCode(int node) {
    if(vcodes[node] == -1){
        vcodes[node] = this->i + 1;
        this->i++;
    }
    return vcodes[node];
}

void WeinbergVector::recursiveCal(WeinbergVertex* node, WeinbergEdge* cameFrom) {
    if(node->getRightMostNeighbor(cameFrom) == NULL){
        printf("weinberg code:");
        for(int i : weinbergCode){
            cout << i << ",";
        }
        printf("\n");
        printf("\n");
        return;
    }

    int code;
    WeinbergVertex* vertex;
    WeinbergEdge* edge;
    if(!node->old){
        node->old = true;
        WeinbergEdge* b = node->getRightMostNeighbor(cameFrom);
        int sec = getSecond(node, b);
        code = this->getVCode(sec);
        b->updateStatus();
        edge = b;
        vertex = graph->vertices[sec];
    }
    else{
        if(cameFrom->getStatus() == WeinbergEdge::NEW){
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
            if(b->getEdge().second == sec){
                code = this->getVCode(b->getEdge().second);
            }
            else{
                code = this->getVCode(b->getEdge().first);
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

void WeinbergVector::reset() {
    for(WeinbergEdge* e : graph->edges){
        e->reset();
    }
    for(WeinbergVertex* v : graph->vertices){
        v->reset();
    }

    for(WeinbergVertex* v : graph->vertices){
        vcodes[v->data] = -1;
    }
    weinbergCode.clear();
    this->i = 0;

}