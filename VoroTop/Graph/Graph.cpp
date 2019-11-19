//
// Created by atara on 9/23/19.
//

#include <sstream>
#include "Graph.h"

void Graph::create(string faces) {
    this->getFaces(faces);
    this->getVertices();
    this->getEdges();
}



