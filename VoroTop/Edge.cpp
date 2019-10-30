//
// Created by atara on 9/23/19.
//

#include "Edge.h"
#include <iostream>

Edge::Edge(int u, int v) {
    this->u= std::min(u,v);
    this->v = std::max(u,v);
}

Edge::Edge(const Edge& e) {
    this->u = e.u;
    this->v = e.v;
}

int Edge::getU() {
    return this->u;
}

int Edge::getV() {
    return this->v;
}

/*bool Edge::operator==(const Edge &e) {
    if(this->u == e.u && this->v == e.v){
        std::cout << "returning true" << std::endl;
        return true;
    }

    std::cout << "returning false" << std::endl;
    return false;

}*/

bool Edge::operator<(const Edge &other) {
    if(this->u == other.u){
        return (this->v < other.v);
    }
    else{
        return (this->u < other.u);
    }
}

void Edge::print() {
    std::cout << "(" << u << "," << v << ")" << std::endl;
}