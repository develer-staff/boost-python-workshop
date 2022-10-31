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
