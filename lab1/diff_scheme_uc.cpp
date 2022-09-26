//
// Created by Мария on 26.09.2022.
//

#include <vector>
#include "../tools/gauss_method.cpp"

/***
 * Метод, вычисляющий коэффициенты в n-точечном шаблоне для производной (в долях шага шаблона h)
 * @param points - коэффициенты, при h для каждой точки в шаблоне
 * @return коэффициенты в n-точечном шаблоне для производной (в долях шага шаблона h)
 */
std::vector<double> firstDer(std::vector<double> points) {
    matrix A{}; //TODO: формирование матрицы
    //...
    std::vector<double> b{}; //TODO: формирование свободных членов
    //...
    return GaussMethod(A, b);
}