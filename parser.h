#ifndef PARSER_H__
#define PARSER_H__

#include <iostream>
#include <string>

using namespace std;

class parser
{
public:
    static const char* NUMBERS_;

    parser(string input);
    bool next();
    int expr();
    int term();
    int factor();
    int variable();
    void convert();
    string constant();
    string digit();

    string token;
    string prev_token;
    string leme;
    string dig;
    string number;
    int result;
    int x;
    int y;
    int z;


private:
    string lexemes;
    int pos;
};

#endif
