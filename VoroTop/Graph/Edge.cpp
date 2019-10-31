//
// Created by atara on 9/23/19.
//

#include "Edge.h"
#include <set>
#include <iostream>

Edge::Edge(std::pair<int, int> edge) {
    this->edge = edge;
}

std::pair<int,int> Edge::getEdge() {
    return edge;
}

void Edge::updateStatus() {
    if(this->status == NOTVISITED){
        this->status = NEW;
    }
    else{
        this->status = OLD;
    }
}

int Edge::getStatus() {
    return this->status;
}

void Edge::print() {
    std::cout << "(" << edge.first << "," << edge.second << ")" << std::endl;
}