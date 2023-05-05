#ifndef SHUNTING_YARD_H
#define SHUNTING_YARD_H

#include <cassert>
#include <iostream>

#include "../linked_list/queue/MyQueue.h"
#include "../linked_list/stack/MyStack.h"

#include "../shunting_yard//leftparen.h"
#include "../shunting_yard/logical.h"
#include "../shunting_yard/relational.h"
#include "../shunting_yard/rightparen.h"
#include "../shunting_yard/token.h"
#include "../shunting_yard/tokenstr.h"
using namespace std;

class ShuntingYard{
private:
    Queue<Token*> _queue;
    bool _error;

public:
    // CTOR
    ShuntingYard(){
        this->_queue = Queue<Token*>();
        this->_error = false;
    }
    explicit ShuntingYard(const Queue<Token*>& input_q){
        this->_queue = input_q;
        this->_error = false;
    }

    // save input_q to member variable queue
    void infix(const Queue<Token*>& input_q){
        this->_queue = input_q;
        this->_error = false;
    }

    // generate postfix queue from infix queue
    Queue<Token*> postfix(){    return this->shunting_yard();}
    Queue<Token*> postfix(const Queue<Token*>& input_q){
        this->_queue = input_q;
        this->_error = false;
        return this->shunting_yard();
    }

    // called by postfix()
    Queue<Token*> shunting_yard();
    bool is_error() const { return this->_error; }
};

#endif // SHUNTING_YARD_H