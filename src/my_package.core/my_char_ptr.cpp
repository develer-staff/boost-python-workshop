#include "my_char_ptr.h"

#include <boost/python.hpp>

struct my_char_ptr_to_memoryview
{
    static PyObject* convert(const my_char_ptr& cpp_obj)
    {
        return PyMemoryView_FromMemory(
                const_cast<char*>(cpp_obj.ptr()), cpp_obj.size(), PyBUF_READ);
    }
};

// Reference:
// https://www.boost.org/doc/libs/1_74_0/libs/python/doc/html/reference/to_from_python_type_conversion/boost_python_to_python_converter.html
void my_char_ptr::export_class_converter()
{
    boost::python::to_python_converter<my_char_ptr, my_char_ptr_to_memoryview>();
}
