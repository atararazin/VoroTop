//
// Created by atara on 9/19/19.
//

#include "FlagParser.h"

FlagParser::FlagParser(string* flag) {
    flagStr = flag;
}

void FlagParser::parse() {
    enum stringVal{ f, w, d, g, r, c, od, o } ;
    std::map<std::string ,stringVal> map;
    map["-f"] = f;
    map["-w"] = w;
    map["-d"] = dd;
    map["-g"] = g;
    map["-r"] = r;
    map["-c"] = c;
    map["-od"] = od;
    map["-o"] = o;

    int flag = map[argv[d]];
    switch(flag){
        case f:
            break;
        case w:
            break;
        default:
            cout << "invalid flag" << endl;
            exit(-1);
    }

}
