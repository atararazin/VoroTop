//
// Created by atara on 10/13/19.
//

#include "FacesToGraph.h"
#include "Graph/Graph.h"
#include "WeinbergAlgorithm/WeinbergGraph.h"
using namespace std;
template <typename T>

void FacesToGraph<T>::openOutputFile() {
    file.open("inputForVoro++.txt.vol");
    this->createGraph();
}

template <typename T>
vector<WeinbergGraph<T>*>& FacesToGraph<T>::createGraph() {
    //vector<Graph*> graphs;
    string line;
    while(getline(file, line)){
        WeinbergGraph<T>* graph = new WeinbergGraph<T>();
        std::cout<< line << std::endl;
        //line = "(0,1,2) (0,2,3) (0,3,4) (0,4,5,6,7) (5,6,8) (0,1,7) (8,6,7,1)";
        line = "(1,4,2,9) (1,0,8,4) (1,9,5,3,0) (2,6,7,5,9) (2,4,8,6) (3,7,6,8,0) (3,5,7)";
        graph->create(line);
        graphs.push_back(graph);
    }
    return graphs;
}

template <typename T>
FacesToGraph<T>::~FacesToGraph() {
    for(WeinbergGraph<T>* g : graphs){
        delete g;
    }
    //delete this;
}