#pragma once

#include <string>

class my_class
{
public:
    void say_hello() const;

    const char* get_name() const;
    void set_name(const char* name);

    static void export_class();

private:
    std::string m_name;
};
