#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "VoronoiCell.h"
#include "FacesToGraph.h"
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/adjacency_list.hpp>
#include "WeinbergVector.h"
using namespace boost;

using namespace std;


int main(int argc, char *argv[]) {
    std::cout << "Hello, Vorotop!" << std::endl;
    fstream file;
    file.open(argv[1]);
    fstream& fref = file;

    Input* input = new Input(fref);
    input->max_x = argv[2];
    input->min_x = argv[3];
    input->max_y = argv[4];
    input->min_y = argv[5];
    input->max_z = argv[6];
    input->min_z = argv[7];
    file.close();

    VoronoiCell* voronoiCell = new VoronoiCell();
    voronoiCell->calcVorCell(input);
    FacesToGraph* graphConverter = new FacesToGraph();
    graphConverter->openOutputFile();
    vector<Graph*> allGraphs = graphConverter->createGraph();
    for(Graph* graph : allGraphs){
        WeinbergVector* wvector = new WeinbergVector(graph);
        wvector->calculate();
    }

    delete(input);
    delete(voronoiCell);
    delete(graphConverter);
    //delete(wvector);
}
