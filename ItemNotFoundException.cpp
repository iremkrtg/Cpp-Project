#include "ItemNotFoundException.h"

ItemNotFoundException::ItemNotFoundException():msg("")
{
}

ItemNotFoundException::ItemNotFoundException(std::string msg) : msg(msg)
{
}

const char* ItemNotFoundException::what() const noexcept
{
	return msg.c_str();
}