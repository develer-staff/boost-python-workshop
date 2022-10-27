#include "my_class.h"

#include <boost/python.hpp>

// Reference:
// https://www.boost.org/doc/libs/1_74_0/libs/python/doc/html/tutorial/tutorial/exposing.html
void my_class::export_class()
{
    boost::python::class_<my_class> my_class_("my_class");
}
