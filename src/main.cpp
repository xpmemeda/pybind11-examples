#include <pybind11/pybind11.h>
#include <vector>
#include <assert.h>

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


namespace py=pybind11;

PYBIND11_MODULE(cmake_example, m) {
    m.doc() = "pybind11 cmake example";
    m.def("add", &add, "A function which adds two numbers");
    m.def("sub", [](int i, int j) { return i - j; }, "A function which subtract two numbers");
    m.def("add_vector", &add_vector);
}