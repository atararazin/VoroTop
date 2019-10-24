#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "VoronoiCell.h"
#include "Input.h"
#include "FlagParser.h"
#include "FacesToGraph.h"
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
    //graphConverter->openOutputFile();
    graphConverter->createAllFaces();

    delete(input);
    delete(voronoiCell);
}
