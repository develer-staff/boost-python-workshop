#pragma once

#include <string>

#include "my_byte_array.h"
#include "my_char_ptr.h"

class my_class
{
public:
    void say_hello() const;

    void sabotage();

    const char* get_name() const;
    void set_name(const char* name);

    my_char_ptr get_name_ptr() const;

    void set_name_in_place(const char* name);

    my_byte_array get_name_as_bytes() const;
    void set_name_as_bytes(const my_byte_array& name);

    static void export_class();

private:
    std::string m_name;
};
