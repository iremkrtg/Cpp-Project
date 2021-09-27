#include "URStack.h"

URStack::URStack(std::stack<Operation> urstack)
{
     this->urstack = urstack;
}

bool URStack::push(Operation op){
    urstack.push(op);
    return true;
}

bool URStack::pop(){
    if(urstack.empty())
        return false;
    else{
       urstack.pop();
       return true;
    }
}
