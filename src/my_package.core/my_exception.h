#pragma once

#include <exception>
#include <string>

class my_exception : public std::exception
{
public:
    explicit my_exception(const std::string& what);

    const char* what() const noexcept override;

private:
    std::string m_what;
};
