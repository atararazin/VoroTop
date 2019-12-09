//
// Created by atara on 9/19/19.
//

#include "WeinbergVector.h"
#include "WeinbergEdge.h"
#include <iostream>

int index = 0;
bool first = true;
bool foundSmaller = false;

/**
 * constructor. Initializes the graph, vertices and edges all from the graph it gets.
 * @param g - the graph we're calculating the Weinberg code on
 * @return
 */
WeinbergVector::WeinbergVector(WeinbergGraph *g) {
    this->graph = g;
    this->vertices = g->vertices;
    this->edges = g->edges;
}

/**
 * prepares for the recusrive part -
 * @param edge - the inital edge (u,v)
 * @param u - the vertex u of edge (u,v)
 * @param v - the vertex v of edge (u,v)
 */
void WeinbergVector::initialize(WeinbergEdge *edge, int u, int v) {
    reset();
    edge->updateStatus();
    vertices[u]->old = true;
    vertices[u]->getWeinNum(&i);
    vertices[v]->getWeinNum(&i);

    /*for printing only*/
    cout << "edge:";
    edge->print();
    printf("");

}

/**
 * runs the Weinberg algorithm on the first edge so that
 * it can compare following Weinberg codes to it.
 */
void WeinbergVector::getFirstWeinVec(){
    int u,v;
    WeinbergEdge* e = edges[0];
    u = e->getEdge().first;
    v = e->getEdge().second;
    this->canonicalVector.push_back(vertices[u]->getWeinNum(&i));
    this->canonicalVector.push_back(vertices[v]->getWeinNum(&i));
    initialize(e, u, v);
    this->recursiveCal(vertices[v], e);
    first = false;
    reset();
}

void WeinbergVector::calculate() {
    int u,v,iter;
    Direction d = Right;
    getFirstWeinVec();

    for(int j = 0; j < 2; j++){
        updateDirection(d);
        for(WeinbergEdge* first : edges){
            for(iter = 0; iter < 2; iter++){
                if(iter == 1){
                    u = first->getOppEdge().first;
                    v = first->getOppEdge().second;
                }
                else{
                    u = first->getEdge().first;
                    v = first->getEdge().second;
                }
                initialize(first, u,v);
                this->recursiveCal(vertices[v], first);
            }
        }
        d = Left;
    }

    /*for printing only*/
    printf("weinberg code:");
       for(int i : canonicalVector){
           cout << i << ",";
       }
       printf("\n");
}


void WeinbergVector::recursiveCal(WeinbergVertex* node, WeinbergEdge* cameFrom) {
    //base condition - if we've reached a node that we've already visited all neighbors
   if(getNeighbor(cameFrom,node) == NULL){
        return;
    }

    WeinbergEdge* edge;
    //if our node has not yet been visited
    if(!node->old){
        node->old = true;
        WeinbergEdge* b = getNeighbor(cameFrom, node);
        edge = b;
    }
    else{//if the node is old, already visited
        //if we haven't yet visited in the opposite direction, visit the opposite direction
        if(cameFrom->getStatus() == WeinbergEdge::NEW){
            edge = cameFrom;
        }
        else{//if we've already visited both directions
            WeinbergEdge* b = getNeighbor(cameFrom, node);
            edge = b;
        }
    }

    edge->updateStatus();
    pair<int,int> directedEdge = edge->getDirectedEdge(node->data);
    WeinbergVertex* vertex = vertices[directedEdge.second];
    int code = vertices[directedEdge.second]->getWeinNum(&i);

    if(!first){
        if (!foundSmaller) {
                //compare our vertices Weinberg code to the canonical vector
                string res = compareToCode(code);
                //if our code is bigger then stop calculating the Weinberg code on this edge
                if (res == "bigger") {
                    return;
                }
                //if it's smaller, update the canonical vector with our Weinberg values
                else if(res == "smaller"){
                    foundSmaller = true;
                    this->canonicalVector[index] = code;
                }
            }
        else{
            this->canonicalVector[index] = code;
        }
        index++;
    }
    else{//if we are in the base iteration, add the code to the vector
        this->canonicalVector.push_back(code);
    }
    recursiveCal(vertex, edge);
}

void WeinbergVector::reset() {
    for(WeinbergEdge* e : edges){
        e->reset();
    }
    for(WeinbergVertex* v : vertices){
        v->reset();
    }
    this->i = 0;
    //index starts at 2 because 0 and 1 are for the first edge's vertices
    index = 2;
    foundSmaller = false;
}


/**
 * change the direction to d, the new direction
 * @param d - the direction we want to update to
 */
void WeinbergVector::updateDirection(Direction d) {
    if(d == Right){
        direction = Right;
    }
    else{//d == Left
        direction = Left;
    }
}

/**
 * get right or left most neighbor, depending on our current direction
 * @param e - the edge we came from
 * @param v - the vertex we are coming from
 * @return the right or left most neighbor
 */
WeinbergEdge* WeinbergVector::getNeighbor(WeinbergEdge *e, WeinbergVertex *v) {
    if(direction == Right){
        right(e,v);
    }
    else{//direction == Left
        left(e,v);
    }
}

WeinbergEdge* WeinbergVector::right(WeinbergEdge *e, WeinbergVertex* v) {
    return v->getRightMostNeighbor(e);
}

WeinbergEdge* WeinbergVector::left(WeinbergEdge *e, WeinbergVertex* v) {
    return v->getLeftMostNeighbor(e);
}

/**
 * compares the current Weinberg code to the code in the same index in the canonical vector.
 * @param i - the current vertex's Weinberg value
 * @return bigger, smaller or equal, depending on the result
 */
string WeinbergVector::compareToCode(int i) {
    if(i > canonicalVector[index]){
        return "bigger";
    }
    else if(i == canonicalVector[index]){
        return "equal";
    }
    else{
        return "smaller";
    }
}