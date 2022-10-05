#include "my_byte_array.h"

#include <boost/python.hpp>

struct my_byte_array_to_bytes
{
    static PyObject *convert(const my_byte_array &cpp_obj)
    {
        return PyBytes_FromStringAndSize(reinterpret_cast<const char *>(cpp_obj.data()), cpp_obj.size());
    }
};

struct my_byte_array_from_bytes
{
    static void *convertible(PyObject *py_obj)
    {
        // Reference:
        // https://docs.python.org/3/c-api/buffer.html
        Py_buffer py_buffer = {};
        if (PyObject_GetBuffer(py_obj, &py_buffer, PyBUF_FORMAT) != 0)
            return nullptr;

        PyBuffer_Release(&py_buffer);
        return py_obj;
    }

    static void construct(PyObject* py_obj, boost::python::converter::rvalue_from_python_stage1_data* data)
    {
        auto rvalue = reinterpret_cast<boost::python::converter::rvalue_from_python_storage<my_byte_array> *>(data);
        void *storage = rvalue->storage.bytes;

        // Reference:
        // https://docs.python.org/3/c-api/buffer.html
        Py_buffer py_buffer = {};
        PyObject_GetBuffer(py_obj, &py_buffer, PyBUF_FORMAT);
        auto cpp_obj = new (storage)my_byte_array(py_buffer.len);
        PyBuffer_ToContiguous(cpp_obj->data(), &py_buffer, py_buffer.len, 'C');
        PyBuffer_Release(&py_buffer);

        data->convertible = storage;
    }
};

// Reference:
// https://www.boost.org/doc/libs/1_74_0/libs/python/doc/html/reference/to_from_python_type_conversion/boost_python_to_python_converter.html
// https://www.boost.org/doc/libs/1_74_0/libs/python/doc/html/faq/how_can_i_automatically_convert_.html
// https://www.boost.org/doc/libs/1_74_0/libs/python/doc/html/reference/high_level_components/boost_python_errors_hpp.html
void my_byte_array::export_class_converter()
{
    boost::python::to_python_converter<my_byte_array, my_byte_array_to_bytes>();
    boost::python::converter::registry::push_back(&my_byte_array_from_bytes::convertible,
                                                  &my_byte_array_from_bytes::construct,
                                                  boost::python::type_id<my_byte_array>());
}
