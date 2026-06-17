#pragma once

#include <exception>
#include <string>

class InvalidBookException : public std::exception
{
public:
    InvalidBookException(const std::string& message);
    const char* what() const noexcept override;

private:
    std::string message_;
};
