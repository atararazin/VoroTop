//
// Created by atara on 11/17/19.
//

#include <sstream>
#include <iostream>
#include "WeinbergGraph.h"
#include "WeinbergEdge.h"

void findInFaces(vector<Face*> faces, int i);
int edgeExists(vector<WeinbergEdge*> edges, pair<int,int>);


void WeinbergGraph::getFaces(string faces) {
    istringstream iss(faces);
    string s;
    while ( getline( iss, s, ' ' ) ) {
        Face* face = new Face();
        face->convertStrToVector(s.c_str());
        this->faces.push_back(face);
    }
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
}

void WeinbergGraph::getEdges() {
    for (WeinbergVertex *vertex : vertices) {
        pair<Face*,int> res = findFirstAppearance(vertex->data);
        Face* face = res.first;
        int index = res.second;
        int n = face->nodes.size();
        int u = face->nodes[index];
        int v = face->nodes[(index + 1) % n];
        pair<int, int> edge(u, v);
        pair<int, int> stoppingE(v,u);
        addEdge(edge, vertex);

        int w = (n + (index-1 % n)) % n ;
        pair<int, int> prevEdge(face->nodes[w], u);
        addEdge(prevEdge, vertex);
        pair<int,int> next = prevEdge;
        while(next != stoppingE){
            res = findPairOfVerticesInFaces(next.second, next.first);
            face = res.first;
            index = res.second;
            n = face->nodes.size();
            u = face->nodes[index];
            w = (n + (index-1 % n)) % n ;

            edge = pair<int,int>(face->nodes[w], u);
            if(edge == stoppingE){
                break;
            }
            addEdge(edge, vertex);
            next = edge;
        }
    }
}

pair<Face*,int> WeinbergGraph::findFirstAppearance(int v) {
    for (Face *f : faces) {
        long n = f->nodes.size();
        for (int i = 0; i < n; i++) {
            if (f->nodes[i] == v) {//find first occurance of v
                return pair<Face*,int>(f,i);
            }
        }
    }
}

/**
 * given a pair of adjacent vertices, find the face they appear in
 * @param v
 * @param u
 * @return returns the first one
 */
pair<Face* ,int> WeinbergGraph::findPairOfVerticesInFaces(int v, int u) {
    for (Face *f : faces) {
        long n = f->nodes.size();
        for (int i = 0; i < n; i++) {
            if (f->nodes[i] == v && f->nodes[(i + 1) % n] == u) {
                return pair<Face* ,int>(f, i);
            }
        }
    }
}

int WeinbergGraph::edgeExists(pair<int, int> searching) {
    int n = edges.size();
    WeinbergEdge* curr;
    for(int i = 0; i < n; i++){
        curr = edges[i];
        if(curr->edge == searching || curr->getOppEdge() == searching){
            return i;
        }
    }
    return -1;
}

void WeinbergGraph::addEdge(pair<int, int> e, WeinbergVertex* v) {
    int ans = edgeExists(e);
    WeinbergEdge* add;
    if(ans >= 0){
        add = edges[ans];
    }
    else{
        WeinbergEdge* newE = new WeinbergEdge(e);
        edges.push_back(newE);
        add = newE;
    }
    v->addEdge(add);
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

WeinbergGraph::~WeinbergGraph() {
    for(Face* f : faces){
        delete(f);
    }
    for(WeinbergEdge* e : edges){
        delete(e);
    }
    for(WeinbergVertex* v : vertices){
        delete(v);
    }
    //delete this;
}