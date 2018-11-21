cmake_minimum_required(VERSION 3.0.2)
project(competitve)

macro (add_options TARG)
    target_compile_options(${TARG} PUBLIC -std=c++14 -Wall -Wextra)
endmacro()

macro (add_optimized_options TARG)
    add_options(${TARG})
    target_compile_options(${TARG} PUBLIC -O3)
endmacro()

macro (add_debug_options TARG)
    add_options(${TARG})
    target_compile_options(${TARG} PUBLIC -O0 -g)
endmacro()

add_executable(tests src/tests/test.cpp src/tests/test_gcd.cpp)
add_debug_options(tests)

add_executable(benchmark.cout src/benchmarks/cout.cpp)
add_optimized_options(benchmark.cout)

add_executable(benchmark.printf src/benchmarks/printf.cpp)
add_optimized_options(benchmark.printf)

add_executable(problem.ringispil problems/ringispil/ringispil.cpp)
add_optimized_options(problem.ringispil)
