project(labs_comp_math)
set (CMAKE_CXX_STANDARD 17)
add_executable(first lab1/main.cpp lab1/diff_scheme_uc.cpp tools/gauss_method.h tools/gauss_method.cpp tools/factorial.cpp tools/factorial.h lab1/diff_scheme_uc.h lab2/newtonian_interpolator.cpp lab2/newtonian_interpolator.h)
