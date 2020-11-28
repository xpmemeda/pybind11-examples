#include <pybind11/pybind11.h>
#include <vector>


namespace py = pybind11;


std::vector<int> square(const std::vector<int>& intput);
py::array py_square(py::array_t<int> array);