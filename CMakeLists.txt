cmake_minimum_required(VERSION 3.5)
project(example)

add_subdirectory(pybind11)

pybind11_add_module(${PROJECT_NAME} src/main.cpp src/numpy_functions.cpp src/custom_class.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)

add_custom_target(
    develop
    COMMAND ${CMAKE_COMMAND} -E create_symlink
      ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.cpython-36m-x86_64-linux-gnu.so
      ${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}.cpython-36m-x86_64-linux-gnu.so
)