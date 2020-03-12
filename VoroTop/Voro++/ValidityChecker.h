//
// Created by atara on 3/12/20.
//


#ifndef VOROTOP_VALIDITYCHECKER_H
#define VOROTOP_VALIDITYCHECKER_H
#include <fstream>
#include <iostream>


class ValidityChecker {
public:
    ValidityChecker(std::fstream* f);
    bool check();
private:
    std::fstream* file;
    bool checkTimeStep();
    bool checkNumAtoms();
    bool checkBoxBound();
    bool checkAtoms();


};


#endif //VOROTOP_VALIDITYCHECKER_H
