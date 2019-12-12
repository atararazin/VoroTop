//
// Created by atara on 12/12/19.
//

#ifndef VOROTOP_DIRECTION_H
#define VOROTOP_DIRECTION_H


class Direction {
private:
    enum direct {Right, Left};
    direct curr_direction;

public:
    int getDirection();
    void setDirection(std::string d);
};


#endif //VOROTOP_DIRECTION_H
