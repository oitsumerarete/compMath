//
// Created by Мария on 16.11.2022.
//

#include "simpleIteration.h"

/**
* Функция для решения уравнения func(x) = 0 при помощи метода простой итерации с релаксацией
* inital - начальное приближение для решения
* func - функция, корень которой нужно найти
* tau - параметр в методе простой итерации
* numberOfIterations - количество итераций, которое должен освершить метод
**/


//x0 = 0,5

[[nodiscard]] double simpleIterationMethod(double inital, const std::function<double(double)> & func, double tau, unsigned numberOfIterations) noexcept{
    double res = inital;
    for (int i = 0; i < numberOfIterations; ++i) {
        res = tau * func(res) + res;
    }
    return res;
}


//для зависимости ошибки от числа итераций
double calc_error(double inital, const std::function<double(double)> &func, const std::function<double(double)> &func_deriv, double tau, unsigned numberOfIterations) {
    double res = inital;
    double error = func(res) / func_deriv(res);
    for (int i = 0; i < numberOfIterations; ++i) {
        res = tau * func(res) + res;
        error = error * (1 + tau * func_deriv(res));
    }
    return error;
}


// //для зависимости ошибки от тау
// void variate_tau(double inital, const std::function<double(double)> &func, const std::function<double(double)> &func_deriv, double tau, unsigned numberOfIterations) {
    
// }