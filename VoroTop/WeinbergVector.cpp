//
// Created by atara on 9/19/19.
//

#include "WeinbergVector.h"
#include <iostream>
#include <iterator>
#include <map>

map<int, int> vcodes;
std::map<int,int>::iterator iter;

void WeinbergVector::calculate(Graph* graph) {
    printf("\n");
    printf("calc");
    this->i = 0;
    for(Vertex* v : graph->vertices){
        vcodes.insert({v->data, -1});
    }

    //for(Edge* e : graph.edges){
        Edge * e = graph->edges.at(0);
        e->print();
        //this->recursiveCal();
    //}
}


int WeinbergVector::getVCode(int node) {
    if(vcodes[node] == -1){
        vcodes[node] = this->i + 1;
        this->i++;
    }
    return vcodes[node];
}

void WeinbergVector::recursiveCal(Vertex node, Edge* cameFrom, Edge* original) {
    if(cameFrom->getEdge() == original->getEdge()){
        return;
    }

    if(!node.old){
        node.old = true;
        Edge* b = node.getRightMostNeighbor();
        int code = this->getVCode(b->getEdge().second);
        this->weinbergCode.push_back(code);
        b->updateStatus();
        recursiveCal(b->getEdge().second, b, cameFrom);
    }
    else{
        if(cameFrom->getStatus()==cameFrom->NEW){
            cameFrom->updateStatus();
            int code = this->getVCode(cameFrom->getEdge().second);
            this->weinbergCode.push_back(code);
            recursiveCal(cameFrom->getEdge().first, cameFrom, original);
        }
        else{
            Edge* b = node.getRightMostNeighbor();
            int code = this->getVCode(b->getEdge().second);
            this->weinbergCode.push_back(code);
            b->updateStatus();
            recursiveCal(b->getEdge().second, b, original);
        }
    }
}