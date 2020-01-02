//
// Created by atara on 10/13/19.
//

#include "FacesToGraph.h"
#include "Graph.h"
#include "../WeinbergAlgorithm/WeinbergGraph/WeinbergGraph.h"
using namespace std;
template <typename T>

void FacesToGraph<T>::openOutputFile(string filePath) {
    //file.open("inputForVoro++.txt.vol");
    try{
        file.open(filePath);
    }
    catch(char* excp){
        cout << "Caught " << excp << endl;
    }
    countNumberFiles();
}

template <typename T>
int FacesToGraph<T>::getNumOfGraphs() {
    return numOfLines;
}
template <typename T>
vector<WeinbergGraph<int>*>& FacesToGraph<T>::createGraph() {
    throw("make one graph at a time- dont use this method");
    exit(234);
}

template <typename T>
void FacesToGraph<T>::countNumberFiles() {
    string line;
    numOfLines = 0;
    while(getline(file, line)){
        numOfLines++;
    }
    file.clear();
    file.seekg(0, ios::beg);
}


template <typename T>
WeinbergGraph<T>* FacesToGraph<T>::createSingleGraph() {
    string line;
    getline(file,line);
    WeinbergGraph<T>* graph = new WeinbergGraph<T>(line);
    return graph;
}

template <typename T>
FacesToGraph<T>::~FacesToGraph() {
    //for(WeinbergGraph<T>* g : graphs){
    //    delete g;
    //}
}

template class FacesToGraph<int>;
