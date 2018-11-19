cmake_minimum_required(VERSION 3.0.2)
project(competitve)
add_executable(tests src/tests/test.cpp src/tests/test_gcd.cpp)
target_compile_options(tests PUBLIC -std=c++14)
