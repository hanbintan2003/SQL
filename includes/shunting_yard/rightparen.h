#ifndef RIGHTPAREN_H
#define RIGHTPAREN_H
#include "token.h"

class RightParen : public Token{
private:
    string _str;

public:
    RightParen(){this->_str = ")";}
    ~RightParen() = default;
    TokenType token_type() const override { return TOKEN_RIGHTPAREN; }
    string token_string() const override { return this->_str; }
    void print(ostream& outs) const override { outs << this->_str; }
    int precedence() const override { return -1; }
    friend ostream& operator<<(ostream& outs, const RightParen& token){
        token.print(outs);
        return outs;
    }
    friend ostream& operator<<(ostream& outs, const RightParen* token){
        token->print(outs);
        return outs;
    }
};

#endif