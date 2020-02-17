//
// Created by atara on 1/9/20.
//

#include "WeinbergGraph/WeinbergVertex.h"
#include "CanonicalVector.h"
#include "WeinbergAlgorithm.h"
#include<algorithm>

template <typename T>
WeinbergAlgorithm<T>::WeinbergAlgorithm(int u, int v, bool direction, vector<WeinbergVertex<int>*> &vertices, bool firstIteration,
                                     CanonicalVector *canonicalVector) {
    this->direction = direction;
    this->vertices = vertices;
    this->firstIteration = firstIteration;
    this->canonicalVector = canonicalVector;
    //this->dirPtr = this->getNeighbor();
    this->WeinbergNumVector = std::vector<int>(vertices.size(), -1);
    this->visitedVertex = std::vector<int>(vertices.size());

    //initialize
    visitedVertex[vertices[u]->data] = 1;
    int codeU = getWeinNum(&vertices[u]->data);
    int codeV = getWeinNum(&vertices[v]->data);
    if(firstIteration){
        canonicalVector->addToVector(codeU);
        canonicalVector->addToVector(codeV);
    }
}

template <typename T>
void WeinbergAlgorithm<T>::recursiveCal(WeinbergVertex<int> *node, WeinbergEdge<int> *cameFrom) {
    //run until weve reached a node that we've already visited all neighbors
    while(getNeighbor(cameFrom,node) != NULL){
        //case 1: new node - has not been visited
        if(visitedVertex[node->data] == 0){
            visitedVertex[node->data] = 1;//asign as discovered
            cameFrom  = getNeighbor(cameFrom, node);//get new neighbor
        }
        //case 2: new node (ie already been discovered)
        else{

            //case 2a: if we have visited the edge already in both directions, get a new edge
            if(cameFrom->getStatus() != WeinbergEdge<int >::NEW) {
                cameFrom = getNeighbor(cameFrom, node);
            }
        }
        cameFrom->updateStatus();

        pair<int,int> directedEdge = cameFrom->getDirectedEdge(node->data);
        node = vertices[directedEdge.second];
        int code = getWeinNum(&node->data);

        if(firstIteration){
            canonicalVector->addToVector(code);
            continue;
        }

        if(foundSmaller){
            canonicalVector->changeCurrValue(code);
        }
        else{
            //compare our vertices Weinberg code to the canonical vector
            string res = canonicalVector->compareToCode(code);

            //if our code is bigger then stop calculating the Weinberg code on this edge
            if (res == "bigger") {
                break;
            }
                //if it's smaller, update the canonical vector with our Weinberg values
            else if(res == "smaller"){
                foundSmaller = true;
                canonicalVector->changeCurrValue(code);
            }
        }


        canonicalVector->incrementIndex();
    }
}

template <typename T>
int WeinbergAlgorithm<T>::getWeinNum(int* data) {
    int val = WeinbergNumVector[*data];
    if(val == -1){
        WeinbergNumVector[*data] = ++i;
        return i;
    }
    return val;
}

/**
 *
 * get right or left most neighbor, depending on our current direction
 * @param e - the edge we came from
 * @param v - the vertex we are coming from
 * @return the right or left most neighbor
 */
template <typename T>
WeinbergEdge<int>* WeinbergAlgorithm<T>::getNeighbor(WeinbergEdge<int> *e, WeinbergVertex<int> *v) {
    if(direction == 0){
        return v->getRightMostNeighbor(e);
    }
    else{
        return v->getLeftMostNeighbor(e);
    }
}

template class WeinbergAlgorithm<int>;
