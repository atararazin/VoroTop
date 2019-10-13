//
// Created by atara on 10/13/19.
//

#ifndef VOROTOP_FACESTOGRAPH_H
#define VOROTOP_FACESTOGRAPH_H
#include <fstream>
#include <iostream>
using namespace std;

class FacesToGraph {
public:
    void openOutputFile();
    void createAllFaces();
    void getAllVertices();
    void getAllEdges();
private:
    fstream file;
};


#endif //VOROTOP_FACESTOGRAPH_H
