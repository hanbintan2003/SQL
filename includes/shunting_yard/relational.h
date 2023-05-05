#ifndef RELATIONAL_H
#define RELATIONAL_H
#include "token.h"

class Relational : public Token{
private:
    string _str;

public:
    Relational(){this->_str = "";}
    explicit Relational(const string& input){this->_str = input;}
    ~Relational() = default;
    TokenType token_type() const override { return TOKEN_RELATIONAL; }
    string token_string() const override { return this->_str; }
    int precedence() const override{
        if (this->_str == "<" || this->_str == ">" || this->_str == "<=" || this->_str == ">=" || this->_str == "=" || this->_str == "!=" || this->_str == "LIKE") return 4;
        else return -1;

    }
    void print(ostream& outs) const override { outs << this->_str; }
    friend ostream& operator<<(ostream& outs, const Relational& token){
        token.print(outs);
        return outs;
    }
    friend ostream& operator<<(ostream& outs, const Relational* token){
        token->print(outs);
        return outs;
    }
};

#endif