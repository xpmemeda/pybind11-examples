cmake_minimum_required(VERSION 3.5)
project(cmake_example)

add_subdirectory(pybind11)
pybind11_add_module(cmake_example src/main.cpp)


add_custom_target(
    develop
    COMMAND ${CMAKE_COMMAND} -E create_symlink
      ${CMAKE_CURRENT_BINARY_DIR}/cmake_example.cpython-36m-x86_64-linux-gnu.so
      ${CMAKE_CURRENT_SOURCE_DIR}/cmake_example.cpython-36m-x86_64-linux-gnu.so
)