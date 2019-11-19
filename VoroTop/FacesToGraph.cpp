//
// Created by atara on 10/13/19.
//

#include "FacesToGraph.h"
#include "Graph/Graph.h"
#include "WeinbergGraph.h"
using namespace std;

void FacesToGraph::openOutputFile() {
    file.open("inputForVoro++.txt.vol");
    std::cout<< "file opened" << std::endl;
    this->createGraph();
}

vector<WeinbergGraph*>& FacesToGraph::createGraph() {
    //vector<Graph*> graphs;
    string line;
    while(getline(file, line)){
        WeinbergGraph* graph = new WeinbergGraph();
        std::cout<< line << std::endl;
        //line = "(0,1,2) (0,2,3) (0,3,4) (0,4,5,6,7) (5,6,8) (0,1,7) (8,6,7,1)";
        line = "(1,4,2,9) (1,0,8,4) (1,9,5,3,0) (2,6,7,5,9) (2,4,8,6) (3,7,6,8,0) (3,5,7)";
        graph->create(line);
        graphs.push_back(graph);
    }
    return graphs;
}
