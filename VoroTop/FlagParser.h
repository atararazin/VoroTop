//
// Created by atara on 9/19/19.
//

#ifndef VOROTOP_FLAGPARSER_H
#define VOROTOP_FLAGPARSER_H


class FlagParser {
private:
    string flagStr;
public:
    FlagParser(string*);
    void parse();
};


#endif //VOROTOP_FLAGPARSER_H
