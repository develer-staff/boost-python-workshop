#pragma once

#include <cstdint>
#include <vector>

class my_byte_array : public std::vector<uint8_t>
{
public:
    using std::vector<uint8_t>::vector;
};
