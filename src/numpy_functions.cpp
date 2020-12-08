#ifndef _NUMPY_FUNCTIONS_H_
#define _NUMPY_FUNCTIONS_H_

#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <vector>

std::vector<int> square(const std::vector<int>& input) {
    size_t n = input.size() / 2;
    std::vector<int> output(n * 3);
    for (int i = 0; i < n; ++i) {
        output[i * 3] = input[i * 2];
        output[i * 3 + 1] = input[i * 2 + 1];
        output[i * 3 + 2] = input[i * 2] * input[i * 2 + 1];
    }
    return output;
}

namespace py = pybind11;

py::array py_square(py::array_t<int> array) {
    if (array.ndim() != 2) {
        throw std::runtime_error("Input should be 2-D NumPy array");
    }
    if (array.shape()[1] != 2) {
        throw std::runtime_error("Input should be size [N, 2]");
    }
    std::vector<int> input(array.size());
    std::memcpy(input.data(), array.data(), array.size() * sizeof(int));
    std::vector<int> output = square(input);
    ssize_t ndim = 2;
    std::vector<ssize_t> shape = {array.shape()[0], 3};
    std::vector<ssize_t> stride = {sizeof(int) * 3, sizeof(int)};
    return py::array(py::buffer_info(
        output.data(),
        sizeof(int),
        py::format_descriptor<int>::format(),
        ndim,
        shape,
        stride
    ));
}


#endif