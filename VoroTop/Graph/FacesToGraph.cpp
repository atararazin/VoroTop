//
// Created by atara on 10/13/19.
//

#include "FacesToGraph.h"
#include "Graph.h"
#include "../WeinbergAlgorithm/WeinbergGraph/WeinbergGraph.h"
using namespace std;
template <typename T>

void FacesToGraph<T>::openOutputFile() {
    file.open("inputForVoro++.txt.vol");
    this->createGraph();
}

template <typename T>
vector<WeinbergGraph<T>*>& FacesToGraph<T>::createGraph() {
    string line;
    while(getline(file, line)){
        WeinbergGraph<T>* graph = new WeinbergGraph<T>(line);
        graphs.push_back(graph);
    }
    return graphs;
}

template <typename T>
FacesToGraph<T>::~FacesToGraph() {
    for(WeinbergGraph<T>* g : graphs){
        delete g;
    }
}

template class FacesToGraph<int>;
