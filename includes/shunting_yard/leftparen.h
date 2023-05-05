#ifndef LEFTPAREN_H
#define LEFTPAREN_H
#include "token.h"

class LeftParen : public Token{
private:
    string _str;

public:
    LeftParen(){this->_str = "(";}
    ~LeftParen() = default;
    TokenType token_type() const override { return TOKEN_LEFTPAREN; }
    string token_string() const override { return this->_str; }
    void print(ostream& outs) const override { outs << this->_str; }
    int precedence() const override { return -1; }
    friend ostream& operator<<(ostream& outs, const LeftParen& token){
        token.print(outs);

        return outs;
    }
    friend ostream& operator<<(ostream& outs, const LeftParen* token){
        token->print(outs);
        return outs;
    }
};

#endif