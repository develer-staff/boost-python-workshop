#pragma once

#include <string>

#include "my_char_ptr.h"

class my_class
{
public:
    void say_hello() const;

    const char* get_name() const;
    void set_name(const char* name);

    my_char_ptr get_name_ptr() const;

    static void export_class();

private:
    std::string m_name;
};
