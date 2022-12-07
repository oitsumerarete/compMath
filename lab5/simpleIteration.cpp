//
// Created by Мария on 16.11.2022.
//

#include "simpleIteration.h"
[[nodiscard]] double simpleIterationMethod(double inital, const std::function<double(double)> & func, double tau, unsigned numberOfIterations) noexcept{
    double res = inital;
    for (int i = 0; i < numberOfIterations; i++) {
        res = func(res);
    }
    return res;
}