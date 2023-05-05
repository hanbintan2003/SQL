#ifndef TOKENSTR_H
#define TOKENSTR_H
#include "token.h"

class TokenStr : public Token{
private:
    string _str;

public:
    TokenStr(){this->_str = "";}
    explicit TokenStr(const string& input){this->_str = input;}
    ~TokenStr() = default;
    TokenType token_type() const override { return TOKEN_TOKENSTR; }
    string token_string() const override { return this->_str; }
    void print(ostream& outs) const override { outs << this->_str; }
    int precedence() const override { return -1; }
    friend ostream& operator<<(ostream& outs, const TokenStr& token){
        token.print(outs);
        return outs;
    }
    friend ostream& operator<<(ostream& outs, const TokenStr* token){
        token->print(outs);
        return outs;
    }
};

#endif