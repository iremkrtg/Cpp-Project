#include "InvalidDayException.h"

InvalidDayException::InvalidDayException():msg("")
{
}

InvalidDayException::InvalidDayException(std::string msg):msg(msg)
{
}

const char* InvalidDayException::what() const throw()
{
    return msg.c_str();
}
