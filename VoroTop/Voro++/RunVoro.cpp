//
// Created by atara on 9/15/19.
//

#include <unistd.h>
#include "RunVoro.h"

/***
 * goes into the directory ./voro++-0.4.6 and compiles voro++ using "make"
 * then goes into "./src" and runs the executable it just made.
 * Finally creates the output file with that voro++ returns.
 * @param inputForVoro
 * @return
 */
VoroOutFile* RunVoro::calcVorCell(Input* inputForVoro) {
    string params = inputForVoro->getInputString();
    chdir("./voro++-0.4.6");
    try{
        system("make");
    }
    catch(...){
        cout << "VoroTop: couldn't compile voro++" << endl;
        exit(0);
    }
    chdir("./src");
    try{
        system(params.c_str());
    }
    catch(...){
        cout << "VoroTop: couldn't run voro++" << endl;
        exit(0);
    }
    VoroOutFile* retFile = new VoroOutFile("inputVoro++.vol");
    //change back to the original directory
    chdir("..");
    chdir("..");
    return retFile;
}

