//
// Created by atara on 11/17/19.
//

#include <sstream>
#include <iostream>
#include "WeinbergGraph.h"
#include "WeinbergEdge.h"

template <typename T>
void WeinbergGraph<T>::getFaces(string faces) {
    istringstream iss(faces);
    string s;
    while ( getline( iss, s, ' ' ) ) {
        Face<T>* face = new Face<T>();
        face->convertStrToVector(s.c_str());
        this->faces.push_back(face);
    }
}

/**
 * creates vertices from faces.
 * The edges are always ordered 0 to n-1 (where n-1 is the number of vertices)
 * Therefore, we just found the max vertex in the faces and made our vertices from 0 to that number.
 */
template <typename T>
void WeinbergGraph<T>::getVertices() {
    //find the max element in the faces
    int max = 0;
    for(Face<T>* f : this->faces){
        for(int vertex : f->nodes){
            max = std::max(vertex, max);
        }
    }

    //create the vertices from 0 to n-1
    for(int i = 0; i <= max; i++){
        WeinbergVertex<int>* vertex = new WeinbergVertex<int>(i);
        this->vertices.push_back(vertex);
    }
}

template <typename T>
void WeinbergGraph<T>::getEdges() {
    for (WeinbergVertex<int> *vertex : vertices) {
        pair<Face<T>*,int> res = findFirstAppearance(vertex);

        Face<T>* face = res.first;
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

template <typename T>
pair<Face<T>*,int> WeinbergGraph<T>::findFirstAppearance(WeinbergVertex<int>* v) {
    for (Face<T> *f : this->faces) {
        long n = f->nodes.size();
        for (int i = 0; i < n; i++) {
            //find first occurance of v
            if (f->nodes[i] == v->data) {
                //if (f->nodes[i] == v) {
                return pair<Face<T>*,int>(f,i);
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
template <typename T>
pair<Face<T>* ,int> WeinbergGraph<T>::findPairOfVerticesInFaces(int v, int u) {
    for (Face<T> *f : this->faces) {
        long n = f->nodes.size();
        for (int i = 0; i < n; i++) {
            if (f->nodes[i] == v && f->nodes[(i + 1) % n] == u) {
                return pair<Face<T>* ,int>(f, i);
            }
        }
    }
}

template <typename T>
int WeinbergGraph<T>::edgeExists(std::pair<T,T> searching) {
    int n = edges.size();
    WeinbergEdge<int>* curr;
    for(int i = 0; i < n; i++){
        curr = edges[i];
        if(curr->forwardEdge() == searching || curr->backwardEdge() == searching){
            //if(curr->edge == searching || curr->backwardEdge() == searching){
            return i;
        }
    }
    return -1;
}

template <typename T>
void WeinbergGraph<T>::addEdge(std::pair<T,T> e, WeinbergVertex<T>* v) {
    int ans = edgeExists(e);
    WeinbergEdge<int>* add;
    if(ans >= 0){
        add = edges[ans];
    }
    else{
        WeinbergEdge<int >* newE = new WeinbergEdge<int >(e);
        edges.push_back(newE);
        add = newE;
    }
    v->addEdge(add);
}

template <typename T>
WeinbergGraph<T>::~WeinbergGraph() {
    for(Face<T>* f : this->faces){
        delete(f);
    }
    for(WeinbergEdge<T >* e : edges){
        delete(e);
    }
    for(WeinbergVertex<T>* v : vertices){
        delete(v);
    }
}

template class WeinbergGraph<int>;
