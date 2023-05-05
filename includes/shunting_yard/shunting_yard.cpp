#include "shunting_yard.h"

// called by postfix()
Queue<Token*> ShuntingYard::shunting_yard(){
    Queue<Token*> output_queue;
    Stack<Token*> operator_stack;

    while (!this->_queue.empty()){
        Token* token = this->_queue.pop();
        // cout << token->token_string() << "," << token->token_type() << endl;
        if (token->token_type() == TOKEN_TOKENSTR){
            output_queue.push(token);
            continue;
        }else if (token->token_type() == TOKEN_LEFTPAREN){
            operator_stack.push(token);
            continue;
        }else if (token->token_type() == TOKEN_RELATIONAL){
            operator_stack.push(token);
            continue;
        }else if (token->token_type() == TOKEN_LOGICAL){
            while (!operator_stack.empty() && operator_stack.top()->token_type() != TOKEN_LEFTPAREN && operator_stack.top()->precedence() >= token->precedence()) output_queue.push(operator_stack.pop());
            // output_queue.push(token);
            operator_stack.push(token);
            continue;
        }else if (token->token_type() == TOKEN_RIGHTPAREN){
            while (!operator_stack.empty() && operator_stack.top()->token_type() != TOKEN_LEFTPAREN){
                output_queue.push(operator_stack.pop());
                if (operator_stack.empty()){
                    output_queue.clear();
                    this->_error = true;
                    return output_queue;
                }
            }

            if (operator_stack.empty() || operator_stack.top()->token_type() != TOKEN_LEFTPAREN){
                output_queue.clear();
                this->_error = true;
                return output_queue;
            }
            operator_stack.pop();
        }
    }
    while (!operator_stack.empty()){
        if (operator_stack.top()->token_type() == TOKEN_LEFTPAREN){
            output_queue.clear();
            this->_error = true;
            return output_queue;
        }
        output_queue.push(operator_stack.pop());
    }
    // cout << output_queue << endl;
    return output_queue;
}
