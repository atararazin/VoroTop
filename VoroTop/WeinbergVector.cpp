//
// Created by atara on 9/19/19.
//

#include "WeinbergVector.h"
#include <iostream>
#include <iterator>
#include <map>

map<int, int> vcodes;
std::map<int,int>::iterator iter;

WeinbergVector::WeinbergVector(Graph *g) {
    this->graph = g;
}

void WeinbergVector::calculate() {
    printf("\n");
    printf("calc");
    this->i = 0;
    for(Vertex* v : graph->vertices){
        vcodes.insert({v->data, -1});
    }

    //for(Edge* e : graph.edges){
    graph->vertices[0]->print();

    Edge * e = graph->edges.at(0);
    e->updateStatus();
    int u = e->getEdge().first;
    int v = e->getEdge().second;
    this->weinbergCode.push_back(this->getVCode(u));
    this->weinbergCode.push_back(this->getVCode(v));
    Edge* right = graph->vertices[v]->getRightMostNeighbor();
    right->print();
    this->recursiveCal(graph->vertices[v], right,e);
    //}
}


int WeinbergVector::getVCode(int node) {
    if(vcodes[node] == -1){
        vcodes[node] = this->i + 1;
        this->i++;
    }
    return vcodes[node];
}

void WeinbergVector::recursiveCal(Vertex* node, Edge* cameFrom, Edge* original) {
    /*if(cameFrom->getEdge() == original->getEdge()){
        for(int i : this->weinbergCode){
            cout << i << "," << endl;
        }
        printf("returning");
        return;
    }

    if(!node->old){
        node->old = true;
        Edge* b = node->getRightMostNeighbor();
        int code = this->getVCode(b->getEdge().second);
        this->weinbergCode.push_back(code);
        b->updateStatus();
        int v = b->getEdge().second;
        recursiveCal(graph->vertices[v], b, cameFrom);
    }
    else{
        if(cameFrom->getStatus()==cameFrom->NEW){
            cameFrom->updateStatus();
            int code = this->getVCode(cameFrom->getEdge().second);
            this->weinbergCode.push_back(code);
            int u = cameFrom->getEdge().first;
            recursiveCal(graph->vertices[u], cameFrom, original);
        }
        else{
            Edge* b = node->getRightMostNeighbor();
            int code = this->getVCode(b->getEdge().second);
            this->weinbergCode.push_back(code);
            b->updateStatus();
            int v = b->getEdge().second;
            recursiveCal(graph->vertices[v], b, original);
        }
    }*/
}