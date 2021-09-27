#ifndef URSTACK_H
#define URSTACK_H
#include "Performance.h"
#include "Operation.h"

#include <stack>


class URStack
{
public:
    URStack(std::stack<Operation> urstack);

    bool push(Operation op);

    bool pop();

    bool isEmpty();



private:
    std::stack<Operation> urstack;

};

#endif // URSTACK_H
