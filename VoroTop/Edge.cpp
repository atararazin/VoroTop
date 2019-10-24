//
// Created by atara on 9/23/19.
//

#include "Edge.h"
#include <iostream>

Edge::Edge(int u, int v) {
    this->u= std::min(u,v);
    this->v = std::max(u,v);
}

void Edge::print() {
    std::cout << "(" << u << "," << v << ")" << std::endl;
}