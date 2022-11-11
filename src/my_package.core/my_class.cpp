#include "my_class.h"

#include <iostream>

#include <boost/python.hpp>

#include "my_exception.h"

void my_class::say_hello() const
{
    std::cout << "Hello there! I'm a C++ method." << std::endl;
}

void my_class::sabotage()
{
    throw my_exception("This is my error string");
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

my_char_ptr my_class::get_name_ptr() const
{
    return my_char_ptr(m_name.c_str(), m_name.size());
}

void my_class::set_name_in_place(const char* name)
{
    const size_t name_size = std::strlen(name);
    const size_t chars_to_copy = std::min(name_size, m_name.size());
    std::memcpy(const_cast<char*>(m_name.c_str()), name, chars_to_copy);
    std::cout << "my_class::set_name_in_place('" << name << "'): " << chars_to_copy
              << " chars replaced." << std::endl;
}

my_byte_array my_class::get_name_as_bytes() const
{
    const auto begin = reinterpret_cast<const uint8_t*>(m_name.c_str());
    const auto end = begin + m_name.length();
    return my_byte_array(begin, end);
}

void my_class::set_name_as_bytes(const my_byte_array& name)
{
    const auto begin = reinterpret_cast<const char*>(name.data());
    m_name = std::string(begin, name.size());
}

// Reference:
// https://www.boost.org/doc/libs/1_74_0/libs/python/doc/html/tutorial/tutorial/exposing.html
void my_class::export_class()
{
    boost::python::class_<my_class> my_class_("my_class");
    my_class_.def("say_hello", &my_class::say_hello);
    my_class_.def("sabotage", &my_class::sabotage);
    my_class_.add_property("name", &my_class::get_name, &my_class::set_name);
    my_class_.add_property("name_ptr", &my_class::get_name_ptr);
    my_class_.def("set_name_in_place", &my_class::set_name_in_place);
    my_class_.add_property(
            "name_as_bytes", &my_class::get_name_as_bytes, &my_class::set_name_as_bytes);
}
