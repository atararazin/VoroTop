//
// Created by atara on 10/13/19.
//

#ifndef VOROTOP_FACESTOGRAPH_H
#define VOROTOP_FACESTOGRAPH_H
#include <fstream>
#include <iostream>
#include "Graph/Graph.h"
#include "WeinbergGraph.h"

using namespace std;

class FacesToGraph {
public:
    void openOutputFile();
    vector<WeinbergGraph*>& createGraph();
    ~FacesToGraph();
private:
    fstream file;
    vector<WeinbergGraph*> graphs;
};


#endif //VOROTOP_FACESTOGRAPH_H
