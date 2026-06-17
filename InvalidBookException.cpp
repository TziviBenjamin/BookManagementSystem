#include "InvalidBookException.h"

InvalidBookException::InvalidBookException(const std::string& message)
    : message_(message)
{
}

const char* InvalidBookException::what() const noexcept
{
    return message_.c_str();
}
