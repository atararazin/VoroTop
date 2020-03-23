//
// Created by atara on 3/3/20.
//

#ifndef VOROTOP_WEINBERGALGORITHM_H
#define VOROTOP_WEINBERGALGORITHM_H

template <typename T>
class WeinbergAlgorithm{
public:
    WeinbergAlgorithm(vector<WeinbergVertex<int>*> &vertices, CanonicalVector *canonicalVector);
    void recursiveCal(WeinbergVertex<int> *node, WeinbergEdge<int> *cameFrom);
    void init(int u, int v);
    void updateDir(int d);
    bool firstIteration = true;


private:
    int direction;
    vector<WeinbergVertex<int>*> vertices;
    CanonicalVector* canonicalVector;
    std::vector<int> WeinbergNumVector;
    std::vector<int> visitedVertex;
    int i = 0;
    bool foundSmaller = false;
    int getWeinNum(int* data);
    WeinbergEdge<int>* getNeighbor(WeinbergEdge<int> *e, WeinbergVertex<int> *v);


    };

#endif //VOROTOP_WEINBERGALGORITHM_H