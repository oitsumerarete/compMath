project(labs_comp_math)
set (CMAKE_CXX_STANDARD 17)
add_executable(first lab1/main.cpp lab1/diff_scheme_uc.cpp tools/gauss_method.cpp)
