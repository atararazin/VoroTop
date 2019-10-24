//
// Created by atara on 9/23/19.
//

#include <sstream>
#include <iostream>
#include <algorithm>
#include "Graph.h"


void Graph::getFaces(string faces) {
    istringstream iss(faces);
    cout << faces << endl;
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

void Graph::printV() {
    for(int i=0; i<this->nodes.size(); ++i)
        nodes[i]->print();
    std::cout << "" <<std::endl;

}


void Graph::getVertices(string faces) {
    vector<int> tempNodes;
    for(Face* f : this->faces){
        for(string edge : f->nodes){
            tempNodes.push_back(stoi(edge));
        }
    }

    vector<int>::iterator ip;
    vector<int> ret = removeDups(tempNodes, ip);
    for(int i: ret){
        Vertex* vertex = new Vertex(i);
        this->nodes.push_back(vertex);
    }
    /*std::sort(tempNodes.begin(), tempNodes.end());
    ip = std::unique(tempNodes.begin(), tempNodes.end());
    tempNodes.resize(std::distance(tempNodes.begin(), ip));

    for (ip = tempNodes.begin(); ip != tempNodes.end(); ++ip) {
        cout << *ip << " ";
        Vertex* vertex = new Vertex(*ip);
        this->nodes.push_back(vertex);
    }*/

    this->printV();
}

void Graph::getEdges() {
    for(Face* f : this->faces){
        int i;
        long n = f->nodes.size();
        for(i = 0; i < n - 1; i++){
            Edge* edge = new Edge(stoi(f->nodes[i]), stoi(f->nodes[i + 1]));
            this->edges.push_back(edge);
        }

        Edge* edge = new Edge(stoi(f->nodes[n-1]), stoi(f->nodes[0]));
        this->edges.push_back(edge);
    }

    this->printE();
}

void Graph::printE() {
    for(int i=0; i<this->edges.size(); ++i)
        edges[i]->print();
    std::cout << "" <<std::endl;

}

template<typename T>
vector<T> Graph::removeDups(vector<T> v, typename vector<T>::iterator ip) {

    std::sort(v.begin(), v.end());
    ip = std::unique(v.begin(), v.end());
    v.resize(std::distance(v.begin(), ip));

    for (ip = v.begin(); ip != v.end(); ++ip) {
        cout << *ip << " ";
        //Vertex* vertex = new Vertex(*ip);
        //insertVec.push_back(vertex);
    }
    return v;
}