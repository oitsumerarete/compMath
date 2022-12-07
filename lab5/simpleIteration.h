//
// Created by Мария on 16.11.2022.
//

#ifndef LABS_COMP_MATH_SIMPLEITERATION_H
#define LABS_COMP_MATH_SIMPLEITERATION_H
#include "functional"
#include "cmath"
[[nodiscard]] double simpleIterationMethod(double inital, const std::function<double(double)> & func, double tau, unsigned numberOfIterations) noexcept;
#endif //LABS_COMP_MATH_SIMPLEITERATION_H
