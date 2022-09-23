#pragma once

#include <stddef.h>
#include <utility>

class my_char_ptr : std::pair<const char *, size_t> {
public:
    my_char_ptr(const char *ptr, size_t size) : std::pair<const char *, size_t>(ptr, size) {}

    const char *ptr() const { return first; }

    size_t size() const { return second; }

    static void export_class_converter();
};
