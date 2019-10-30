//
// Created by atara on 10/13/19.
//

#include "FacesToGraph.h"
#include "Graph.h"
using namespace std;

void FacesToGraph::openOutputFile() {
    file.open("inputForVoro++.txt.vol");
    std::cout<< "file opened" << std::endl;
    this->createAllFaces();
}

void FacesToGraph::createAllFaces() {
    string line;
    while(getline(file, line)){
        Graph* graph = new Graph();
        std::cout<< line << std::endl;
        //line = "(1,2,3) (1,3,4) (1,4,5) (1,5,6,7,8) (9,6,7) (1,2,8) (7,9,2)";
        graph->getFaces(line);
        graph->getVertices(line);
        graph->getEdges();
    }
}