//
// Created by atara on 11/17/19.
//

#include <sstream>
#include <iostream>
#include "WeinbergGraph.h"


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
        Vertex* vertex = new Vertex(i);
        this->vertices.push_back(vertex);
    }


    /*for printing only*/
    printf("vertices:");
    //printV();
}

void WeinbergGraph::getEdges() {
    //std::set<pair<int,int>> tempEdge;
    std::vector<Vertex*>::iterator it;

    for(Face* f : this->faces){
        long n = f->nodes.size();
        for(int i = 0; i < n; i++){
            int u = f->nodes[i];
            int v = f->nodes[(i + 1) % n];
            pair<int, int> edge(u,v);
            Edge curr = Edge(edge);
            bool found = 0;
            for(Edge* e : edges){
                if(e->edge == pair<int,int>(v,u)){
                    found = 1;
                    vertices[u]->addEdge(e);
                    break;
                }
            }
            //didnt find (v,u)
            if(found == 0){
                Edge* newEdge = new Edge(edge);
                edges.push_back(newEdge);
                vertices[u]->addEdge(newEdge);

            }

            /*//if edge (u,v) already exists as (v,u)

            if(otherDirIn(tempEdge, edge)){
                it = std::find(vertices.begin(), vertices.end(), Vertex(u));
                vertices[u]->addEdge()
                tempEdge.insert(edge);
            }*/
        }
    }

    printG();
}

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
    for(Vertex* v : vertices){
        printf("vertex:\n");
        v->print();
        printf("edges:");
        for(Edge* edge : v->getEdges()){
            edge->print();
            printf(",");
        }
        printf("\n\n");
    }
}

