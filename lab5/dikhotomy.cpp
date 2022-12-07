//
// Created by Мария on 05.11.2022.
//
#include "dikhotomy.h"
[[nodiscard]] double bisectionMethod(double a, double b, const std::function<double(double)> & func, unsigned numberOfIterations) noexcept{
    unsigned k = 1;
    while (numberOfIterations > k){
        double c = (a+b)/2;
        if (func(b)*func(c) < 0) a = c;
        else b = c;
        k++;
    }
    return (a+b)/2;
}

