#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <iomanip>
#include <cassert>
#include <string>

#include "../map/map.h"
#include "../map/mmap.h"
#include "../tokenizer/stokenize.h"

enum Ptype{
    CREATE = 0,
    TABLE = 1,
    FIELDS = 2,
    INSERT = 3,
    INTO = 4,
    VALUES = 5,
    SELECT = 6,
    ASTERISK = 7,
    FROM = 8,
    WHERE = 9,
    LITERAL = 10,
    COMMAS = 11,
    PARENS = 12,
    RELATIONAL = 13,
    LOGICAL = 14,
    QUOTE = 15,
};

class Parser{
public:
    // Constructors
    Parser();
    Parser(const char*& cstr);
    Parser(const string& str);
    // save string to private member
    void set_string(const char*& cstr);
    void set_string(const string& str);
    // parse string to map
    MMap<string, string> parse_tree();
    vector<SToken> get_input();

private:
    vector<SToken> input;
    vector<Ptype> types;
    MMap<string, string> tree;
    STokenizer token;
    int table[MAX_ROWS][MAX_COLUMNS];
    // helper
    void tokenize();
    void init_();
    bool parse();
};

#endif // PARSER_H