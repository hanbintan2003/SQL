#ifndef STRING_TOKEN_H
#define STRING_TOKEN_H

#include <iostream>
#include <string>
#include "constants.h"

using namespace std;

class SToken{
private:
    string _token;
    STRING_TOKEN_TYPES _type;

public:
    // Constructors
    SToken(): _token(""), _type(TOKEN_UNKNOWN){}
    SToken(string str, STRING_TOKEN_TYPES type)
        : _token(str), _type(type)
    {}
    // return the type of the token
    STRING_TOKEN_TYPES type() const { return _type; }
    // return the token string
    string token_str() const { return _token; }
    // return the type of the token as a string
    string token_type() const{
        if (this->_type == TOKEN_ALPHA) return "ALPHA";
        if (this->_type == TOKEN_NUMBER) return "NUMBER";
        if (this->_type == TOKEN_SPACE) return "SPACE";
        if (this->_type == TOKEN_OPERATOR) return "OPERATOR";
        if (this->_type == TOKEN_COMMA) return "COMMA";
        if (this->_type == TOKEN_PAREN) return "PAREN";
        if (this->_type == TOKEN_STAR) return "STAR";
        return "UNKNOWN";
    }
    // overload the << operator
    friend ostream& operator<<(ostream& outs, const SToken& t)
    {
        outs << "|" << t.token_str() << '|';
        return outs;
    }

};

#endif // STRING_TOKEN_H