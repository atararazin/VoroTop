//
// Created by atara on 11/17/19.
//

#include "WeinbergEdge.h"

WeinbergEdge::WeinbergEdge(std::pair<int, int> edge) : Edge(edge){
    this->edge = edge;
}

void WeinbergEdge::updateStatus() {
    if(this->status == NOTVISITED){
        this->status = NEW;
    }
    else{
        this->status = OLD;
    }
}


int WeinbergEdge::getStatus() {
    return this->status;
}

std::pair<int, int> WeinbergEdge::getOppEdge() {
    return std::pair<int,int>(edge.second,edge.first);
}


void WeinbergEdge::reset() {
    this->status = NOTVISITED;
}