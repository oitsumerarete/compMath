//
// Created by Мария on 27.09.2022.
//

#ifndef LABS_COMP_MATH_GAUSS_METHOD_H
#define LABS_COMP_MATH_GAUSS_METHOD_H

#include <vector>

using matrix = std::vector<std::vector<double>>;

std::vector<double> GaussMethod(matrix A, std::vector<double> b);
std::vector<double> gauss(matrix a, std::vector<double> y);
#endif //LABS_COMP_MATH_GAUSS_METHOD_H
