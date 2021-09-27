#ifndef OPERATION_H
#define OPERATION_H

#include "Performance.h"

typedef enum{
    ADD,
    REMOVE,
    UPDATE,
    ADD_LIST,
    REMOVE_LIST
}OperationType;

class Operation
{
public:
    Operation(OperationType type, Performance* performance);
    ~Operation();


    OperationType getType();
    bool setType(OperationType type);

    Performance* getPerf();
    bool setPerf(Performance* performance);

private:
    OperationType type;
    Performance* performance;

};

#endif // OPERATION_H
