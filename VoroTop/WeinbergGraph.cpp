//
// Created by atara on 11/17/19.
//

#include <sstream>
#include <iostream>
#include "WeinbergGraph.h"
#include "WeinbergEdge.h"


void WeinbergGraph::getFaces(string faces) {
    istringstream iss(faces);
    string s;
    while ( getline( iss, s, ' ' ) ) {
        Face* face = new Face();
        face->convertStrToVector(s.c_str());
        this->faces.push_back(face);
    }

    /*for printing only*/
    cout << "printing faces" << endl;
    //this->printFaces();
}

void WeinbergGraph::getVertices() {
    int max = 0;
    for(Face* f : this->faces){
        for(int edge : f->nodes){
            max = std::max(edge, max);
        }
    }

    for(int i = 0; i <= max; i++){
        WeinbergVertex* vertex = new WeinbergVertex(i);
        this->vertices.push_back(vertex);
    }


    /*for printing only*/
    printf("vertices:");
    //printV();
}

void WeinbergGraph::getEdges() {
    for(Face* f : this->faces){
        long n = f->nodes.size();
        for(int i = 0; i < n; i++){
            int u = f->nodes[i];
            int v = f->nodes[(i + 1) % n];
            pair<int, int> edge(u,v);
            Edge curr = Edge(edge);
            bool found = 0;
            for(WeinbergEdge* e : edges){
                if(e->edge == pair<int,int>(v,u)){
                    found = 1;
                    vertices[u]->addEdge(e);
                    break;
                }
            }
            //didnt find (v,u)
            if(found == 0){
                WeinbergEdge* newEdge = new WeinbergEdge(edge);
                edges.push_back(newEdge);
                vertices[u]->addEdge(newEdge);

            }
        }
    }

    printG();
}

/*
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
}*/

/*for printing only*/
void WeinbergGraph::printFaces() {
    for(int i=0; i<this->faces.size(); ++i)
        faces[i]->print();
    std::cout << "" <<std::endl;

}

/*for printing only*/
void WeinbergGraph::printV() {
    for(int i=0; i<this->vertices.size(); ++i)
        vertices[i]->print();
    std::cout << "" <<std::endl;

}

/*for printing only*/
void WeinbergGraph::printE() {
    for(int i=0; i<this->edges.size(); ++i)
        edges[i]->print();
    std::cout << "" <<std::endl;

}


void WeinbergGraph::printG() {
    printf("graph:\n");
    for(WeinbergVertex* v : vertices){
        printf("vertex:\n");
        v->print();
        printf("edges:");
        for(WeinbergEdge* edge : v->getEdges()){
            edge->print();
            printf(",");
        }
        printf("\n\n");
    }
}

