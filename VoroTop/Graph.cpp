//
// Created by atara on 9/23/19.
//

#include <sstream>
#include <iostream>
#include <algorithm>
#include <set>
#include "Graph.h"

bool isDup(Edge* e, vector<Edge*> curr);
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
    vector<Edge*> tempEdge;
    for(Face* f : this->faces){
        int i;
        long n = f->nodes.size();
        for(i = 0; i < n - 1; i++){
            int u = stoi(f->nodes[i]);
            int v = stoi(f->nodes[i + 1]);
            Edge* edge = new Edge(u ,v);
            if(!isDup(edge, tempEdge)){
                tempEdge.push_back(edge);
            }
        }

        Edge* edge = new Edge(stoi(f->nodes[n-1]), stoi(f->nodes[0]));
        if(!isDup(edge, tempEdge)){
            tempEdge.push_back(edge);
        }

    }

    //this->removeDupsEdges(tempEdge);
    for(int i=0; i<tempEdge.size(); ++i)
        tempEdge[i]->print();

    this->printE();
}

bool isDup(Edge* e, vector<Edge*> curr){
    for(Edge* other : curr){
        if(e->getU() == other->getU() && e->getV() == other->getV()){
            delete(e);
            return true;
        }
    return false;
    }
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
    }
    return v;
}

//MAKE THIS GOOD CODE AND REMOVE THIS FUNCTION
void Graph::removeDupsEdges(vector<Edge*> vec) {
    //vector<Edge*>::iterator iter;
    //sort( vec.begin(), vec.end() , iter);
    //sort(vec.begin(), vec.end());
    //vec.erase( unique( vec.begin(), vec.end() ), vec.end() );
/*    set<Edge*> s;
    int size = vec.size();
    for(int i = 0; i < size; ++i ){
        s.insert( vec[i] );
    }
    vec.assign( s.begin(), s.end() );
*/
    for(int i=0; i<vec.size(); ++i)
        vec[i]->print();
}

