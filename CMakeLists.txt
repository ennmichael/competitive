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

add_executable(problem_ciode problems/ciode-2009-opstinsko/ciode.cpp)
add_debug_options(problem_ciode)

add_executable(problem_rubik problems/rubik-2009-opstinsko/rubik.cpp)
add_debug_options(problem_rubik)

add_executable(problem_prva_cifra problems/prva-cifra-2018-kvalifikacije/prva_cifra.cpp)
add_debug_options(problem_prva_cifra)

add_executable(problem_transformacija_matrice problems/transformacija-matrice-2018-kvalifikacije/transformacija_matrice.cpp)
add_debug_options(problem_transformacija_matrice)

add_executable(problem_prodavnice problems/prodavnice-2018-kvalifikacije/prodavnice.cpp)
add_debug_options(problem_prodavnice)

# add_executable(problem_nagrade problems/nagrade-2018-kvalifikacije/nagrade.cpp)
# add_debug_options(problem_nagrade)

add_executable(problem_mala_matrica problems/mala-matrica-2018-kvalifikacije/mala_matrica.cpp)
add_debug_options(problem_mala_matrica)

add_executable(problem_trivijalan_broj problems/trivijalan-broj-2018-kvalifikacije/trivijalan_broj.cpp)
add_debug_options(problem_trivijalan_broj)

add_executable(problem_topla_voda problems/topla-voda-2018-kvalifikacije/topla_voda.cpp)
add_debug_options(problem_topla_voda)

add_executable(problem_najblizi_neopadajuci problems/najblizi-neopadajuci-2018-kvalifikacije/najblizi_neopadajuci.cpp)
add_debug_options(problem_najblizi_neopadajuci)

add_executable(check_stirling library/check_stirling.cpp)
add_optimized_options(check_stirling)

add_executable(playground library/playground.cpp)
add_debug_options(playground)
