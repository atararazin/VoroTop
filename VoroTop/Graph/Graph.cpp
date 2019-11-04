//
// Created by atara on 9/23/19.
//

#include <sstream>
#include <iostream>
#include <algorithm>
#include <set>
#include "Graph.h"

bool otherDirIn(set<pair<int,int>> s, pair<int,int> p);

void Graph::create(string faces) {
    this->getFaces(faces);
    this->getVertices(faces);
    this->getEdges();
    this->assignEdgesToVertices();
}

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
    for(int i=0; i<this->vertices.size(); ++i)
        vertices[i]->print();
    std::cout << "" <<std::endl;

}


void Graph::getVertices(string faces) {
    set<int> tempNodes;
    for(Face* f : this->faces){
        for(string edge : f->nodes){
            tempNodes.insert(stoi(edge));
        }
    }

    for (int i : tempNodes){
        Vertex* vertex = new Vertex(i);
        this->vertices.push_back(vertex);
    }
    printf("vertices:");
    printV();
}

void Graph::getEdges() {
    std::set<pair<int,int>> tempEdge;

    for(Face* f : this->faces){
        int i;
        long n = f->nodes.size();
        for(i = 0; i < n - 1; i++){
            int u = stoi(f->nodes[i]);
            int v = stoi(f->nodes[i + 1]);
            pair<int, int> edge(u,v);
            if(!otherDirIn(tempEdge, edge)){
                tempEdge.insert(edge);

            }
        }

        pair<int,int> edge(stoi(f->nodes[n-1]), stoi(f->nodes[0]));
        if(!otherDirIn(tempEdge, edge)){
            tempEdge.insert(edge);
        }

    }

    for (pair<int,int> e : tempEdge){
        Edge* edge = new Edge(e);
        this->edges.push_back(edge);
    }
    printf("edges:");
    printE();

}

bool otherDirIn(set<pair <int,int>> s, pair <int,int> p) {
    pair<int,int> otherDir(p.second, p.first);
    return(s.find(otherDir) != s.end());
}


void Graph::printE() {
    for(int i=0; i<this->edges.size(); ++i)
        edges[i]->print();
    std::cout << "" <<std::endl;

}

void Graph::assignEdgesToVertices() {
    std::vector<Vertex*>::iterator it;
    for(Edge* e : this->edges){
        int u = e->getEdge().first;
        vertices.at(u)->addEdge(e);
        //it = std::find(vertices.begin(), vertices.end(), Vertex(u));
        //auto index = std::distance(vertices.begin(), it);
        int v = e->getEdge().second;
        vertices.at(v)->addEdge(e);
    }

    for(Vertex* v : vertices){
        cout << v->data << ":" << endl;
        for(Edge* e : v->getEdges()){
            e->print();
        }

    }
}

Graph::~Graph() {
    for(Edge* e: edges){
        delete(e);
    }

    for(Vertex* vertex: vertices){
        delete(vertex);
    }

    for(Face* f : faces){
        delete(f);
    }
    delete(this);
}