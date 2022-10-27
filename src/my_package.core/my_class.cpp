#include "my_class.h"

#include <iostream>

#include <boost/python.hpp>

void my_class::say_hello() const
{
    std::cout << "Hello there! I'm a C++ method." << std::endl;
}

const char* my_class::get_name() const
{
    return m_name.c_str();
}

void my_class::set_name(const char* name)
{
    std::cout << "my_class::set_name('" << name << "')" << std::endl;
    m_name = name;
}

// Reference:
// https://www.boost.org/doc/libs/1_74_0/libs/python/doc/html/tutorial/tutorial/exposing.html
void my_class::export_class()
{
    boost::python::class_<my_class> my_class_("my_class");
    my_class_.def("say_hello", &my_class::say_hello);
    my_class_.add_property("name", &my_class::get_name, &my_class::set_name);
}
