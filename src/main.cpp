#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <vector>
#include <assert.h>

#include "numpy_help.h"

int add(int i, int j) {
    return i + j;
}


std::vector<int> add_vector(const std::vector<int>& x, const std::vector<int>& y) {
    assert(x.size() == y.size());
    std::vector<int> z(x.size());
    for (int i = 0; i < x.size(); ++i) {
        z[i] = x[i] + y[i];
    }
    return z;
}


std::vector<int> mul_by_10(const std::vector<double>& input) {
    std::vector<int> output(input.size());
    for (size_t i = 0; i < input.size(); ++i) {
        output[i] = 10 * static_cast<int>(input[i]);
    }
    return output;
}


namespace py=pybind11;

// wrap C++ function with NumPy array IO
py::array_t<int> py_mul_by_10(py::array_t<double, py::array::c_style | py::array::forcecast> array) {
    // allocate std::vector (to pass to the C++ function)
    std::vector<double> array_vec(array.size());
    // py::array -> std::vector
    std::memcpy(array_vec.data(), array.data(), array.size() * sizeof(double));
    // call C++ function
    std::vector<int> result_vec = mul_by_10(array_vec);
    // allocate py::array (to pass the result of C++ function to Python)
    auto result  = py::array_t<int>(array.size());
    auto result_buffer = result.request();
    int* result_ptr = (int*)result_buffer.ptr;
    // std::vector -> py::array
    std::memcpy(result_ptr, result_vec.data(), result_vec.size() * sizeof(int));

    return result;
}

PYBIND11_MODULE(cmake_example, m) {
    m.doc() = "pybind11 cmake example";
    m.def("add", &add, "A function which adds two numbers");
    m.def("sub", [](int i, int j) { return i - j; }, "A function which subtract two numbers");
    m.def("add_vector", &add_vector);
    m.def("mul_by_10", &py_mul_by_10);
    m.def("square", &py_square);
}