#pragma once

#include <string>

class my_item
{
public:
    const char* get_name() const;
    void set_name(const char* name);

    static void export_class();

private:
    std::string m_name;
};
