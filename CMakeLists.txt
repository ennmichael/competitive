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

add_executable(tests library/tests/test.cpp library/tests/test_gcd.cpp)
add_debug_options(tests)

add_executable(benchmark.cout library/benchmarks/cout.cpp)
add_optimized_options(benchmark.cout)

add_executable(benchmark.printf library/benchmarks/printf.cpp)
add_optimized_options(benchmark.printf)

add_executable(problem.ringispil problems/ringispil-2009-opstinsko/ringispil.cpp)
add_optimized_options(problem.ringispil)

add_executable(problem.palindromi problems/palindromi-2009-opstinsko/palindromi.cpp)
add_optimized_options(problem.palindromi)

add_executable(problem.kondenzatori problems/kondenzatori-2009-opstinsko/kondenzatori.cpp)
add_optimized_options(problem.kondenzatori)
