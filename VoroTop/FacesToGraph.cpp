//
// Created by atara on 10/13/19.
//

#include "FacesToGraph.h"
#include "Graph/Graph.h"
using namespace std;

void FacesToGraph::openOutputFile() {
    file.open("inputForVoro++.txt.vol");
    std::cout<< "file opened" << std::endl;
    this->createGraph();
}

vector<Graph*>& FacesToGraph::createGraph() {
    //vector<Graph*> graphs;
    string line;
    while(getline(file, line)){
        Graph* graph = new Graph();
        std::cout<< line << std::endl;
        //line = "(0,1,2) (0,2,3) (0,3,4) (0,4,5,6,7) (5,6,8) (0,1,7) (8,6,7,1)";
        graph->create(line);
        graphs.push_back(graph);
    }
    return graphs;
}
