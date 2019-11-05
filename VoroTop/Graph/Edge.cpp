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

std::pair<int,int> Edge::getOppEdge() {
    std::pair<int, int> opp(edge.second, edge.second);
    return opp;
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

bool Edge::operator==(const Edge &other) {
    bool same = other.edge.first == this->edge.first && other.edge.second == this->edge.second;
    bool opp = other.edge.first == this->edge.second && other.edge.second == this->edge.first;
    return same || opp;
}

void Edge::print() {
    std::cout << "(" << edge.first << "," << edge.second << ")" << std::endl;
}