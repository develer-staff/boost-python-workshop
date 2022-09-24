#pragma once

#include <string>

#include "my_byte_array.h"
#include "my_char_ptr.h"

class my_class {
public:
    my_class();

    my_class(const my_class &other);

    my_class(my_class &&other);

    ~my_class();

    my_class &operator=(const my_class &other);

    my_class &operator=(my_class &&other);

    void say_hello() const;

    const char *get_name() const;

    void set_name(const char *name);

    my_char_ptr get_name_ptr() const;

    void set_name_in_place(const char *name);

    my_byte_array get_name_as_bytes() const;

    static void export_class();

private:
    std::string m_name {};

};
