#ifndef _NUMPY_FUNCTIONS_H_
#define _NUMPY_FUNCTIONS_H_


#include <pybind11/pybind11.h>
#include <vector>


std::vector<int> square(const std::vector<int>& intput);
pybind11::array py_square(pybind11::array_t<int> array);


void init_numpy_functions(pybind11::module m);

#endif
