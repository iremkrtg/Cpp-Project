#include "Operation.h"

Operation::Operation(OperationType type, Performance* performance){
    this->type = type;
    this->performance = performance;
}

Operation::~Operation(){

}

OperationType Operation::getType(){
    return this->type;
}

bool Operation::setType(OperationType type){
    this->type = type;
    return true;
}

Performance* Operation::getPerf(){
    return this->performance;
}

bool Operation::setPerf(Performance *performance){
    this->performance = performance;
    return true;
}

