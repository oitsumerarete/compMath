project(labs_comp_math)
cmake_minimum_required(VERSION 3.23)
set (CMAKE_CXX_STANDARD 17)

add_executable(first lab1/diff_scheme_uc_upd.cpp lab1/main.cpp lab1/diff_scheme_uc.cpp tools/gauss_method.h tools/gauss_method.cpp tools/factorial.cpp tools/factorial.h lab1/diff_scheme_uc.h )
add_executable(second lab2/newtonian_interpolator.cpp lab2/newtonian_interpolator.h lab2/main.cpp)
add_executable(third lab3/cubic_spline_wiki.cpp lab3/cubic_spline_wiki.h lab3/testing_cubicspline.cpp lab3/cubic_spline.cpp lab3/cubic_spline.h tools/threediagonalsolver.cpp tools/threediagonalsolver.h)
add_executable(fourth lab4/integration.cpp lab4/integration.h)
