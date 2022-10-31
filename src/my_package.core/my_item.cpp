#include "my_item.h"

#include <iostream>

#include <boost/python.hpp>

const char* my_item::get_name() const
{
    return m_name.c_str();
}

void my_item::set_name(const char* name)
{
    std::cout << "my_item::set_name('" << name << "')" << std::endl;
    m_name = name;
}

// Reference:
// https://www.boost.org/doc/libs/1_74_0/libs/python/doc/html/tutorial/tutorial/exposing.html
void my_item::export_class()
{
    boost::python::class_<my_item> my_item_("my_item");
    my_item_.add_property("name", &my_item::get_name, &my_item::set_name);
}
