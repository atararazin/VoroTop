//
// Created by atara on 1/23/20.
//

#ifndef VOROTOP_STATUS_H
#define VOROTOP_STATUS_H


class Status {
public:
    enum stat{NOTVISITED, NEW, OLD};
    stat currentStatus = NOTVISITED;
};


#endif //VOROTOP_STATUS_H
