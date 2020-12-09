#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <vector>
#include <string>
#include <assert.h>

#include "numpy_functions.h"
#include "custom_class.h"


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


py::module submodule(py::module parent, const char* name, const char* doc) {
    auto m = parent.def_submodule(name, doc);
    m.attr("__package__") = parent.attr("__name__");
    return m;
}

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


PYBIND11_MODULE(example, m) {
    m.attr("__name__") = "example";
    m.attr("__package__") = m.attr("__name__");
    m.doc() = "pybind11 and cmake example";
    m.def("add", &add, "A function which adds two numbers");
    m.def("sub", [](int i, int j) { return i - j; }, "A function which subtract two numbers");
    m.def("add_vector", &add_vector);
    m.def("mul_by_10", &py_mul_by_10);
    auto custom_class = submodule(m, "custom_class", "custom class");
    auto numpy_functions = submodule(m, "numpy_functions", "numpy functions");
    init_custom_class(custom_class);
    init_numpy_functions(numpy_functions);
}
// PYBIND11_MODULE(example, m) {
//     m.doc() = "pybind11 and cmake example";
//     m.def("add", &add, "A function which adds two numbers");
//     m.def("sub", [](int i, int j) { return i - j; }, "A function which subtract two numbers");
//     m.def("add_vector", &add_vector);
//     m.def("mul_by_10", &py_mul_by_10);
//     m.def("square", &py_square);
//     py::class_<Pet>(m, "Pet")
//         .def(py::init<const std::string&>())
//         .def("setName", &Pet::setName)
//         .def("getName", &Pet::getName)
//         .def_property("name", &Pet::getName, &Pet::setName)
//         .def_readwrite("public_name", &Pet::public_name)
//         .def("__repr__",
//             [](const Pet& a) {
//                 return "<example.Pet public named '" + a.public_name + "'>";
//             }
//         );
//     py::class_<Dog, Pet>(m, "Dot")
//         .def(py::init<const std::string&>())
//         .def("bark", &Dog::bark);
//     m.def("get_dog", [](std::string name) { return std::unique_ptr<Dog>(new Dog(name)); });
// }