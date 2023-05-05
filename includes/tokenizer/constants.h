#ifndef TOKENIZER_CONSTANTS_H
#define TOKENIZER_CONSTANTS_H

const int MAX_COLUMNS = 256;
const int MAX_ROWS = 100;
const int MAX_BUFFER = 200;

const char ALPHAS[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_0123456789";
const char DIGITS[] = "0123456789";
const char OPERATORS[] = "><=!";
const char SPACES[] = {' ', '\t', '\n', '\0'};
const char PAREN[] = "()";
const char STAR[] = "*";
const char COMMA[] = ",";

// token types
enum STRING_TOKEN_TYPES{
    TOKEN_NUMBER,
    TOKEN_ALPHA,
    TOKEN_SPACE,
    TOKEN_OPERATOR,
    TOKEN_COMMA,
    TOKEN_PAREN,
    TOKEN_STAR,
    TOKEN_QUOTE,
    TOKEN_UNKNOWN = -1,
};


#endif // TOKENIZER_CONSTANTS_H