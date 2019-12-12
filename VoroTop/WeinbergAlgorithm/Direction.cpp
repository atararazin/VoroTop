//
// Created by atara on 12/12/19.
//
#include <string>
#include "Direction.h"
int Direction::getDirection() {
    return curr_direction;
}

void Direction::setDirection(std::string d) {
    if(d == "Right"){
        curr_direction = direct::Right;
    }
    else{
        curr_direction = direct ::Left;
    }
}

