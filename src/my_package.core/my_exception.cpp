#include "my_exception.h"

#include <boost/python/exception_translator.hpp>

my_exception::my_exception(const std::string& what) : m_what(what) { }

const char* my_exception::what() const noexcept
{
    return m_what.data();
}

// Reference:
// https://www.boost.org/doc/libs/1_51_0/libs/python/doc/v2/exception_translator.html
// https://docs.python.org/3/c-api/exceptions.html
void my_exception::translate(const my_exception& e)
{
    // Use the Python 'C' API to set up an exception object.
    PyErr_SetString(PyExc_RuntimeError, e.what());
}
