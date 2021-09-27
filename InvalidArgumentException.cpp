#include "InvalidArgumentException.h"

InvalidArgumentException::InvalidArgumentException():msg("")
{
}

InvalidArgumentException::InvalidArgumentException(std::string msg):msg(msg)
{
}

const char* InvalidArgumentException::what() const throw()
{
	return msg.c_str();
}
