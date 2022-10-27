#include "my_class.h"

#include <iostream>

#include <boost/python.hpp>

void my_class::say_hello() const
{
    std::cout << "Hello there! I'm a C++ method." << std::endl;
}

// Reference:
// https://www.boost.org/doc/libs/1_74_0/libs/python/doc/html/tutorial/tutorial/exposing.html
void my_class::export_class()
{
    boost::python::class_<my_class> my_class_("my_class");
    my_class_.def("say_hello", &my_class::say_hello);
}
