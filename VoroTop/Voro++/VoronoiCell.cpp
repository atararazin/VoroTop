//
// Created by atara on 9/15/19.
//

#include <unistd.h>
#include "VoronoiCell.h"
#include "Input.h"
#include <experimental/filesystem>


void VoronoiCell::calcVorCell(Input* inputForVoro) {
    string params = inputForVoro->getInputString();
    cout << std::experimental::filesystem::current_path() << endl;
    chdir("./voro++-0.4.6");
    cout << std::experimental::filesystem::current_path() << endl;
    int retcode = system("make");
    chdir("./src");
    int retCode = system(params.c_str());
}

void VoronoiCell::openOutputFile() {
    //
}
