#include <boost/python.hpp>

#include "my_class.h"

BOOST_PYTHON_MODULE(core)
{
    my_class::export_class();
}
