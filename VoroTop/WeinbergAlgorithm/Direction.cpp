//
// Created by atara on 12/12/19.
//
#include <string>
#include "Direction.h"
int Direction::getDirection() {
    return curr_direction;
}

/***
 * given input string d, updates the value of curr_direction
 * @param d
 */
void Direction::setDirection(std::string d) {
    if(d == "Right"){
        curr_direction = direct::Right;
    }
    else{
        curr_direction = direct ::Left;
    }
}

