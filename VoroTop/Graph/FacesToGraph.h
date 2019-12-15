//
// Created by atara on 10/13/19.
//

#ifndef VOROTOP_FACESTOGRAPH_H
#define VOROTOP_FACESTOGRAPH_H
#include <fstream>
#include <iostream>
#include "Graph.h"
#include "../WeinbergAlgorithm/WeinbergGraph/WeinbergGraph.h"

using namespace std;
template <typename T>

class FacesToGraph {
public:
    void openOutputFile();
    vector<WeinbergGraph<T>*>& createGraph();
    ~FacesToGraph();
private:
    fstream file;
    vector<WeinbergGraph<T>*> graphs;
};


#endif //VOROTOP_FACESTOGRAPH_H
