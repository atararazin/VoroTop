//
// Created by atara on 9/15/19.
//

#include "VoronoiCell.h"
#include "Input.h"

void VoronoiCell::calcVorCell(Input* inputForVoro) {
    inputForVoro->updateInputStr();
    string params = inputForVoro->inputStr;
    int retCode = system(params.c_str());
}

void VoronoiCell::openOutputFile() {
    //
}
