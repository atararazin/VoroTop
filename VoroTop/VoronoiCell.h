//
// Created by atara on 9/15/19.
//

#ifndef VOROTOP_VORONOICELL_H
#define VOROTOP_VORONOICELL_H

#include <fstream>
#include "Input.h"

using namespace std;

class VoronoiCell {
public:
    void calcVorCell(Input* inputForVoro);
    void openOutputFile();
};


#endif //VOROTOP_VORONOICELL_H
