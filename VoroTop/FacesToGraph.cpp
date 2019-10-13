//
// Created by atara on 10/13/19.
//

#include "FacesToGraph.h"
#include "Graph.h"
#include "GraphsContainer.h"
using namespace std;

void FacesToGraph::openOutputFile() {
    file.open("inputForVoro++.txt.vol");
    std::cout<< "file opened" << std::endl;
    this->createAllFaces();
}

void FacesToGraph::createAllFaces() {
    string line;
    GraphsContainer* graphsContainer = new GraphsContainer();
    while(getline(file, line)){
        Graph* graph = new Graph();
        std::cout<< line << std::endl;
        graph->convertFromListFaces(line);
    }
}