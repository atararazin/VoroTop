//
// Created by atara on 9/15/19.
//

#ifndef VOROTOP_VORONOICELL_H
#define VOROTOP_VORONOICELL_H
/***
 * Runs Voro++ on file and returns the file voro++ creates
 */

#include <fstream>
#include "Input.h"
#include "../VoroOutFile.h"

using namespace std;

class RunVoro {
public:
    VoroOutFile* calcVorCell(Input* inputForVoro);
};


#endif //VOROTOP_VORONOICELL_H
