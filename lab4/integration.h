//
// Created by Мария on 22.10.2022.
//

#ifndef LABS_COMP_MATH_INTEGRATION_H
#define LABS_COMP_MATH_INTEGRATION_H
#include <functional>
#include <vector>
#include "cmath"
[[nodiscard]] double integrateOneSeg(
        double a,
        double b,
        unsigned n,
        const std::function<double(double)> & func) noexcept;
double integrate(
        double a,
        double b,
        unsigned n,
        unsigned s,
        const std::function<double(double)> & func);
#endif //LABS_COMP_MATH_INTEGRATION_H
