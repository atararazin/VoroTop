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
}

/**
 * creates vertices from faces.
 * The edges are always ordered 0 to n-1 (where n-1 is the number of vertices)
 * Therefore, we just found the max vertex in the faces and made our vertices from 0 to that number.
 */
void WeinbergGraph::getVertices() {
    //find the max element in the faces
    int max = 0;
    for(Face* f : this->faces){
        for(int vertex : f->nodes){
            max = std::max(vertex, max);
        }
    }

    //create the vertices from 0 to n-1
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
        pair<int, int> stoppingE(v, u);
        addEdge(edge, vertex);

        int w = (n + (index-1 % n)) % n ;
        pair<int, int> next(face->nodes[w], u);
        while(next != stoppingE){
            addEdge(next, vertex);
            res = findPairOfVerticesInFaces(next.second, next.first);
            face = res.first;
            index = res.second;
            n = face->nodes.size();
            u = face->nodes[index];
            w = (n + (index-1 % n)) % n ;
            next = pair<int,int>(face->nodes[w], u);
        }
    }
}

pair<Face*,int> WeinbergGraph::findFirstAppearance(int v) {
    for (Face *f : faces) {
        long n = f->nodes.size();
        for (int i = 0; i < n; i++) {
            //find first occurance of v
            if (f->nodes[i] == v) {
                return pair<Face*,int>(f,i);
            }
        }
    }
}

int* WeinbergGraph::findFirstAppearance2(int v) {
    int* ptr;
    for (Face *f : faces) {
        long n = f->nodes.size();
        for (int i = 0; i < n; i++) {
            //find first occurance of v
            if (f->nodes[i] == v) {
                ptr = &f->nodes[i];
                return ptr;
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
        if(curr->forwardEdge() == searching || curr->backwardEdge() == searching){
            //if(curr->edge == searching || curr->backwardEdge() == searching){
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
}