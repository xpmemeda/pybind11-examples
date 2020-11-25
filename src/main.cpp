#include <pybind11/pybind11.h>

int add(int i, int j) {
    return i + j;
}

namespace py=pybind11;

PYBIND11_MODULE(cmake_example, m) {
    m.doc() = "pybind11 cmake example";
    m.def("add", &add, "A function which adds two numbers");
    m.def("sub", [](int i, int j) { return i - j; }, "A function which subtract two numbers");
}