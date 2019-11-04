//
// Created by atara on 9/23/19.
//

#include <iostream>
#include "Vertex.h"

//Vertex::Vertex(int data) {
 //   this->data = data;
//}

int Vertex::getData() const {
    return this->data;
}

void Vertex::print() {
    cout << this->data << endl;
}

void Vertex::addEdge(Edge* e) {
    this->listOfEdges.push_back(e);
}

bool Vertex::operator==(const Vertex &other) const {
    return other.data == data;

}

vector<Edge*> Vertex::getEdges() {
    return this->listOfEdges;
}

bool Vertex::operator()(const Vertex &obj) const {
    return obj.data == data;
}

int Vertex::getWeinNum(int* i) {
    if(this->weinNum == -1){
        this->weinNum = *i+1;
        i++;
    }
    return this->weinNum;
}

Edge* Vertex::getRightMostNeighbor() {
    return this->listOfEdges.at(1);

}