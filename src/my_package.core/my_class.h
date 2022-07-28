#pragma once

#include <string>

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

    static void export_class();

private:
    std::string m_name {};

};
