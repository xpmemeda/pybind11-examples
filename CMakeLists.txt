cmake_minimum_required(VERSION 3.5)
project(_c)

add_subdirectory(pybind11)

aux_source_directory(example/src/ SRCS)

pybind11_add_module(${PROJECT_NAME} ${SRCS})

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/example/include)

add_custom_target(
    develop
    COMMAND ${CMAKE_COMMAND} -E create_symlink
      ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.cpython-36m-x86_64-linux-gnu.so
      ${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}.cpython-36m-x86_64-linux-gnu.so
)