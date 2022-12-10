//
// Created by Мария on 16.11.2022.
//

#ifndef LABS_COMP_MATH_SIMPLEITERATION_H
#define LABS_COMP_MATH_SIMPLEITERATION_H
#include <functional>
#include <cmath>
#include <iostream>

[[nodiscard]] double simpleIterationMethod(double inital, const std::function<double(double)> & func, double tau, unsigned numberOfIterations) noexcept;
double calc_error(double inital, const std::function<double(double)> &func, const std::function<double(double)> &func_deriv, double tau, unsigned numberOfIterations);

#endif //LABS_COMP_MATH_SIMPLEITERATION_H
