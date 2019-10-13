//
// Created by atara on 9/23/19.
//

#include <sstream>
#include <iostream>
#include "Graph.h"

void Graph::convertFromListFaces(string faces) {
    istringstream iss(faces);
    string s;
    while ( getline( iss, s, ' ' ) ) {
        Face* face = new Face();
        face->convertStrToVector(s.c_str());
        this->faces.push_back(face);
    }
    cout << "printing faces" << endl;
    this->printFaces();
}

void Graph::printFaces() {
    for(int i=0; i<this->faces.size(); ++i)
        faces[i]->print();
    std::cout << "" <<std::endl;

}