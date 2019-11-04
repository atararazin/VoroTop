//
// Created by atara on 11/4/19.
//

#include "WeinbergVertex.h"


int WeinbergVertex::getWeinNum(int* i) {
    if(this->weinNum == -1){
        this->weinNum = *i+1;
        i++;
    }
    return this->weinNum;
}
