#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "VoronoiCell.h"
#include "FacesToGraph.h"
#include "WeinbergAlgorithm/WeinbergVector.h"
using namespace std;

#include<gtest/gtest.h>
#include<gmock/gmock.h>


int main(int argc, char*argv[]){
    testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();
    return 0;
}
/*#include<iostream>
using namespace std;


class Complex {
private:
    int real, imag;
public:
    Complex(int r = 0, int i =0)  {
        real = r;
        imag = i;
    }

    // This is automatically called when '+' is used with
    // between two Complex objects
    Complex operator + (Complex const &obj) {
        Complex res;
        res.real = real + obj.real;
        res.imag = imag + obj.imag;
        return res;
    }

    bool operator== (Complex const &obj){
        return obj.imag==imag && obj.real == real;
    }
    void print() { cout << real << " + i" << imag << endl; }
};

int main()
{
    Complex* c1 = new Complex(2, 4);
    Complex* c2 = new Complex(2, 24);
    //Complex c3 = c1 + c2; // An example call to "operator+"
    if(*c1 == *c2){
        printf("true");
    }
    else{
        printf("false");
    }
}
*/


/*
int main(int argc, char *argv[]) {
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
    vector<WeinbergGraph*> allGraphs = graphConverter->createGraph();
    for(WeinbergGraph* graph : allGraphs){
        WeinbergVector* wvector = new WeinbergVector(graph);
        wvector->calculate();
        delete(wvector);
    }

    delete(input);
    delete(voronoiCell);
    delete(graphConverter);
}*/