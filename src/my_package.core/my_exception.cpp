#include "my_exception.h"

my_exception::my_exception(const std::string& what) : m_what(what) { }

const char* my_exception::what() const noexcept
{
    return m_what.data();
}
