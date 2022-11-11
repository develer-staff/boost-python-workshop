#include <boost/python.hpp>
#include <boost/python/exception_translator.hpp>

#include "my_byte_array.h"
#include "my_exception.h"
#include "my_char_ptr.h"
#include "my_class.h"

BOOST_PYTHON_MODULE(core)
{
    my_class::export_class();
    my_char_ptr::export_class_converter();
    my_byte_array::export_class_converter();

    boost::python::register_exception_translator<my_exception>(&my_exception::translate);
}
