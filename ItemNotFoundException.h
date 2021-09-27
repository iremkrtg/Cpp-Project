#pragma once

#include <exception>
#include <string>

class ItemNotFoundException : public std::exception
{
private:
	std::string msg;

public:
	ItemNotFoundException();
	ItemNotFoundException(std::string msg);
	const char* what() const throw ();
};

