//
// Created by atara on 9/23/19.
//

#include <sstream>
#include <iostream>
#include <algorithm>
#include <set>
#include "Graph.h"

bool otherDirIn(set<pair<int,int>> s, pair<int,int> p);
Edge* getRandEdge(vector<Edge*> edges, Vertex* v);


void Graph::create(string faces) {
    this->getFaces(faces);
    this->getVertices(faces);
    this->getEdges();
    //this->assignEdgesToVertices();
}

void Graph::getFaces(string faces) {
    istringstream iss(faces);
    string s;
    while ( getline( iss, s, ' ' ) ) {
        Face* face = new Face();
        face->convertStrToVector(s.c_str());
        this->faces.push_back(face);
    }

    /*for printing only*/
    cout << "printing faces" << endl;
    this->printFaces();
}

/*for printing only*/
void Graph::printFaces() {
    for(int i=0; i<this->faces.size(); ++i)
        faces[i]->print();
    std::cout << "" <<std::endl;

}

/*for printing only*/
void Graph::printV() {
    for(int i=0; i<this->vertices.size(); ++i)
        vertices[i]->print();
    std::cout << "" <<std::endl;

}


void Graph::getVertices(string faces) {
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
    printV();
}

void Graph::getEdges() {
    std::set<pair<int,int>> tempEdge;

    for(Face* f : this->faces){
        int i;
        long n = f->nodes.size();
        for(i = 0; i < n - 1; i++){
            int u = f->nodes[i];
            int v = f->nodes[i + 1];
            pair<int, int> edge(u,v);
            if(!otherDirIn(tempEdge, edge)){
                tempEdge.insert(edge);

            }
        }

        pair<int,int> edge(f->nodes[n-1], f->nodes[0]);
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

/*void Graph::assignEdgesToVertices() {
    std::vector<Vertex*>::iterator it;
    for(Edge* e : this->edges){
        int u = e->getEdge().first;
        vertices.at(u)->addEdge(e);
        int v = e->getEdge().second;
        vertices.at(v)->addEdge(e);
    }

    //printing//
    for(Vertex* v : vertices){
        cout << v->data << ":" << endl;
        for(Edge* e : v->getEdges()){
            e->print();
        }

    }
}*/

/*assigns the list of edges to each vertices, sorted in a counter-clockwise manner*/
/*void Graph::assignEdgesToVertices() {
    std::vector<string>::iterator it;
    std::vector<Edge*>::iterator iter;

    for(Vertex* v: vertices) {
        Edge *e = getRandEdge(this->edges, v);
        for (Face *face: faces) {
            int size = face->nodes.size();
            it = std::find (face->nodes.begin(), face->nodes.end(), e->getEdge().first);
            if (it != face->nodes.end()) {
                int pos = it - face->nodes.begin() + 1;
                if(stoi(face->nodes.at((pos+1) % size)) == e->getEdge().second){
                    std::pair<int,int> p1(stoi(face->nodes.at((pos-1) % size)), v->data);
                    std::pair<int,int> p2(v->data, stoi(face->nodes.at((pos-1) % size)));


                    //get the actual edge found from edges
                    //v->addEdge(found);
                    //find next edge (u, i-1) in edges

                }
            }

        }
    }

}*/

Edge* getRandEdge(vector<Edge*> edges, Vertex* v){
    for(Edge* e : edges){
        if(e->getEdge().first == v->data || e->getEdge().first == v->data){
            return e;
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