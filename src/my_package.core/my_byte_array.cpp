#include "my_byte_array.h"

#include <boost/python.hpp>

struct my_byte_array_to_bytes
{
    static PyObject *convert(const my_byte_array &cpp_obj)
    {
        return PyBytes_FromStringAndSize(reinterpret_cast<const char *>(cpp_obj.data()), cpp_obj.size());
    }
};

// Reference:
// https://www.boost.org/doc/libs/1_74_0/libs/python/doc/html/reference/to_from_python_type_conversion/boost_python_to_python_converter.html
void my_byte_array::export_class_converter()
{
    boost::python::to_python_converter<my_byte_array, my_byte_array_to_bytes>();
}
