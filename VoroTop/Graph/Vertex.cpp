//
// Created by atara on 9/23/19.
//

#include <iostream>
#include "Vertex.h"

/*for printing only*/
void Vertex::print() {
    cout << this->data << endl;
}

void Vertex::printEdges(vector<Edge *> v) {
    for(Edge* e: v){
        e->print();
    }
}

void Vertex::addEdge(Edge* e) {
    this->listOfEdges.push_back(e);
}

vector<Edge*> Vertex::getEdges() {
    return this->listOfEdges;
}

bool Vertex::operator()(const Vertex &obj) const {
    return obj.data == data;
}


bool Vertex::operator==(const Vertex &other) {
    return this->data == other.data;
}