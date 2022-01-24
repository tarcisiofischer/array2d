cmake_minimum_required(VERSION 3.16)
project(array2d)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_executable(run_tests
    array2d.hpp
    catch.hpp
    run_tests.cpp
)
