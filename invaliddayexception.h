#pragma once

#include <exception>
#include <string>

class InvalidDayException : public std::exception
{
private:
    std::string msg;
public:
    InvalidDayException();
    InvalidDayException(std::string msg);
    const char* what() const throw ();
};


