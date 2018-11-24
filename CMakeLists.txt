cmake_minimum_required(VERSION 3.0.2)
project(competitve)

macro (add_options TARG)
    target_compile_options(${TARG} PUBLIC -std=c++14 -Wall -Wextra -Wpedantic)
endmacro()

macro (add_optimized_options TARG)
    add_options(${TARG})
    target_compile_options(${TARG} PUBLIC -O3)
endmacro()

macro (add_debug_options TARG)
    add_options(${TARG})
    target_compile_options(${TARG} PUBLIC -O0 -g)
endmacro()

add_executable(tests library/tests/test.cpp library/tests/test_gcd.cpp library/tests/test_breadth_first_search.cpp library/tests/test_a_star.cpp)
add_debug_options(tests)

add_executable(benchmark_cout library/benchmarks/cout.cpp)
add_optimized_options(benchmark_cout)

add_executable(benchmark_printf library/benchmarks/printf.cpp)
add_optimized_options(benchmark_printf)

add_executable(problem_ringispil problems/ringispil-2009-opstinsko/ringispil.cpp)
add_optimized_options(problem_ringispil)

add_executable(problem_palindromi problems/palindromi-2009-opstinsko/palindromi.cpp)
add_optimized_options(problem_palindromi)

add_executable(problem_kondenzatori problems/kondenzatori-2009-opstinsko/kondenzatori.cpp)
add_optimized_options(problem_kondenzatori)

add_executable(check_stirling library/check_stirling.cpp)
add_optimized_options(check_stirling)

add_executable(playground library/playground.cpp)
add_debug_options(playground)
