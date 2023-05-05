#ifndef LOGICAL_H
#define LOGICAL_H
#include "token.h"

class Logical : public Token{
private:
    string _str;

public:
    Logical(){this->_str = "";}
    explicit Logical(const string& input){this->_str = input;}
    ~Logical() = default;

    TokenType token_type() const override { return TOKEN_LOGICAL; }
    string token_string() const override { return this->_str; }
    int precedence() const override{
        if (this->_str == "not") return 3;
        else if (this->_str == "and") return 2;
        else if (this->_str == "or") return 1;
        else return -1;
    }
    void print(ostream& outs) const override { outs << this->_str; }
    friend ostream& operator<<(ostream& outs, const Logical& token){
        token.print(outs);
        return outs;
    }
    friend ostream& operator<<(ostream& outs, const Logical* token){
        token->print(outs);
        return outs;
    }
};

#endif