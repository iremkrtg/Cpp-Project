#pragma once

#include <exception>
#include <string>

class InvalidArgumentException : public std::exception
{
private:
	std::string msg;
public:
	InvalidArgumentException();
	InvalidArgumentException(std::string msg);
	const char* what() const throw ();
};


