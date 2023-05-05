#include "ftokenize.h"


FTokenizer::FTokenizer(char *fname) {
    this->_pos = 0;
    this->_blockPos = 0;

    this->_f.open(fname);
    assert(this->_f.is_open());

    this->_more = get_new_block();
}

SToken FTokenizer::next_token() {
    SToken token;

    this->_stk >> token;
    this->_pos += token.token_str().length();
    this->_blockPos+= token.token_str().length();

    if (this->_stk.done()) {
        this->_more = get_new_block();
    }

    return token;
}

FTokenizer &operator>>(FTokenizer &f, SToken &t) {
    t = f.next_token();
    return f;
}

bool FTokenizer::get_new_block() {
    if (!this->_f.eof()){
        this->_blockPos=0;
        char buffer[MAX_BLOCK];
        this->_f.read(buffer, MAX_BLOCK-1);

        buffer[this->_f.gcount()] = '\0';
        this->_stk.set_string(buffer);

        cout << "----- New Block ----- [" << _f.gcount() << "] bytes" << endl;
        return true;
    }
    this->_f.close();
    cout << "END OF FILE" << endl;
    return false;
}