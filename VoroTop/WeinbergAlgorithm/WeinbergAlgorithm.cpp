//
// Created by atara on 1/9/20.
//

#include "WeinbergGraph/WeinbergVertex.h"
#include "CanonicalVector.h"
#include "WeinbergAlgorithm.h"
#include<algorithm>

template <typename T>
WeinbergAlgorithm<T>::WeinbergAlgorithm(vector<WeinbergVertex<int>*> &vertices, CanonicalVector *canonicalVector) {
    this->vertices = vertices;
    this->canonicalVector = canonicalVector;
}

template <typename T>
void WeinbergAlgorithm<T>::init(int u, int v) {
    this->i = 0;
    foundSmaller = false;
    this->WeinbergNumVector = std::vector<int>(vertices.size(), -1);
    this->visitedVertex = std::vector<int>(vertices.size());

    this->firstIteration = firstIteration;
    visitedVertex[vertices[u]->data] = 1;
    int codeU = getWeinNum(&vertices[u]->data);
    int codeV = getWeinNum(&vertices[v]->data);
    if(firstIteration){
        canonicalVector->addToVector(codeU);
        canonicalVector->addToVector(codeV);
    }
}

template <typename T>
void WeinbergAlgorithm<T>::updateDir(int d) {
    this->direction = d;
}

/**
 * the recursive part of the algorithm. The algorithm runs like this:
 * At every iteration, it has a node and the edge it came from. There are three cases:
 * Case 1: the node is a new node that hasn't been visited yet. In this case, assign it as seen and get
 * the right/left most neighbor.
 * Case 2: the node has previously been discovered. If we havent visited the opposite direction
 * as the direction we came from, traverse the opposite edge. Otherwise, get the right/left neighbor.
 * @param node
 * @param cameFrom
 */
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

/***
 * gets the Weinberg Number. If no number has been assigned, assign it with the
 * next availble integer.
 * Otherwise, return the existing number
 * @param data
 * @return
 */
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
