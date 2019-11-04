//
// Created by atara on 10/13/19.
//

#ifndef VOROTOP_FACESTOGRAPH_H
#define VOROTOP_FACESTOGRAPH_H
#include <fstream>
#include <iostream>
#include "Graph/Graph.h"

using namespace std;

class FacesToGraph {
public:
    void openOutputFile();
    vector<Graph*>& createGraph();
private:
    fstream file;
    vector<Graph*> graphs;
};


#endif //VOROTOP_FACESTOGRAPH_H
