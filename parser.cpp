//
// Sergio Gonzalez
// code structure help from Dr. Bunescu
// some collaboration with Zhiqiang Zhang
//

#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>    // std::remove_if
#include "parser.h"

using namespace std;

const char* parser::NUMBERS_ = "0123456789";

parser::parser(string input)
{
    lexemes = input;
    result = 0;
    pos = 0;
    prev_token = "";
    token = "";
    next();
}

// advances the string to the next token
bool parser::next()
{
    if (pos == lexemes.size())
        return false;
    prev_token = token;
    token = lexemes[pos++];
    return true;
}

// <expr> ::= <term> | <term> "+" <expr> | <variable> "=" <expr>
int parser::expr()
{
    result = term();

    if (token == "+")
    {
        next();
        result = result + expr();
    }

    if (token == "=")
    {
        if (prev_token == "x")
        {
            next();
            x = expr();
        }

        if (prev_token == "y")
        {
            next();
            y = expr();
        }

        if (prev_token == "z")
        {
            next();
            z = expr();
        }
    }

    return (result);
}

// <term> ::= <factor> | <term> "*" <factor>
int parser::term()
{
    result = factor();

    if (token == "*")
    {
        next();
        result = result * term();
    }

    return (result);
}

// factor ::= <constant> | <variable> | "(" <expr> ")"
int parser::factor()
{
    if (token == "(")
    {
        next();
        result = expr();
        if (token == ")")
        {
            next();
        }
    }

    if(token == "x"|| token == "y" || token == "z")
    {
        result = variable();
    }

    else
    {
        string get_const;
        get_const = constant();
        istringstream buffer(get_const);
        buffer>>result;
    }

    return (result);
}

// <variable> ::= "x" | "y" | "z"
int parser::variable()
{
    if (token == "x")
    {
        next();
        return x;
    }

    if (token == "y")
    {
        next();
        return y;
    }

    if (token == "z")
    {
        next();
        return z;
    }
}

// <constant> ::= <digit> | <digit> <constant>
string parser::constant()
{
    dig = digit();

    if (next())
    {
        if (token.find_first_of(NUMBERS_) != std::string::npos)
        {
            dig = dig + constant();
        }
    }

    return (dig);
}

// <digit> ::= "0"|"1"|"2"|"3"|"4"|"5"|"6"|"7"|"8"|"9"
string parser::digit()
{
    if (token.find_first_of(NUMBERS_) != std::string::npos)
    {
        string num = token;
        return (num);
    }

    else
        return "";
}

int main()
{
    string input;
    float answer = 0;
    while (1)
    {
        cout << "Input mathematic expression: ";
        getline(cin, input);
        input.erase(std::remove_if(input.begin(), input.end(), ::isspace), input.end());
        parser p(input);
        answer = p.expr();
        cout << answer << endl;
    }

    return (0);
}