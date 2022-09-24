#include <boost/python.hpp>

#include "my_class.h"
#include "my_char_ptr.h"
#include "my_byte_array.h"

BOOST_PYTHON_MODULE(core)
{
    my_class::export_class();
    my_char_ptr::export_class_converter();
    my_byte_array::export_class_converter();
}
