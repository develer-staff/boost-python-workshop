#include "my_class.h"

#include <iostream>

#include <boost/python.hpp>

my_class::my_class()
{
    std::cout << "[C++] my_class constructor." << std::endl;
}

my_class::~my_class()
{
    std::cout << "[C++] my_class destructor." << std::endl;
}

my_class::my_class(const my_class &other)
{
    std::cout << "[C++] my_class copy constructor." << std::endl;
}

my_class::my_class(my_class &&other)
{
    std::cout << "[C++] my_class move constructor." << std::endl;
}

my_class &my_class::operator=(const my_class &other)
{
    std::cout << "[C++] my_class copy operator." << std::endl;

    return *this;
}

my_class &my_class::operator=(my_class &&other)
{
    std::cout << "[C++] my_class move constructor." << std::endl;

    return *this;
}

void my_class::say_hello() const
{
    std::cout << "[C++] Hello there! I'm a C++ method." << std::endl;
}

const char *my_class::get_name() const
{
    return m_name.c_str();
}

void my_class::set_name(const char *name)
{
    std::cout << "[C++] set_name: " << name << std::endl;
    m_name = name;
}

my_char_ptr my_class::get_name_ptr() const
{
    return my_char_ptr(m_name.c_str(), m_name.size());
}

void my_class::set_name_in_place(const char *name)
{
    const size_t name_size = std::strlen(name);
    const size_t chars_to_copy = std::min(name_size, m_name.size());
    std::memcpy(const_cast<char *>(m_name.c_str()), name, chars_to_copy);
    std::cout << "[C++] setting name in place: " << chars_to_copy << " chars replaced." << std::endl;
}

// Reference:
// https://www.boost.org/doc/libs/1_74_0/libs/python/doc/html/tutorial/tutorial/exposing.html
void my_class::export_class()
{
    boost::python::class_<my_class> cls("my_class");
    cls.def("say_hello", &my_class::say_hello);
    cls.def("set_name_in_place", &my_class::set_name_in_place);
    cls.add_property("name", &my_class::get_name, &my_class::set_name);
    cls.add_property("name_ptr", &my_class::get_name_ptr);
}
