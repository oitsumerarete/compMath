//
// Created by Мария on 26.09.2022.
//

#include <vector>
#include "cmath"
#include "../tools/factorial.h"
#include "../tools/gauss_method.cpp"

/***
 * Метод, вычисляющий коэффициенты в n-точечном шаблоне для производной (в долях шага шаблона h)
 * @param points - коэффициенты, при h для каждой точки в шаблоне
 * @return коэффициенты в n-точечном шаблоне для производной (в долях шага шаблона h)
 */
std::vector<double> firstDer(std::vector<double> points) {
    matrix A(points.size());
    for (int i = 0; i < points.size(); i++)
        A[i].resize(points.size());
    //...
    /*double h = points[1] - points[0];
    std::vector<double> multi{};
    for (int i = 0; i<points.size()+1; i++){
        multi[i] = points[i]*h;
    }*/

    for (int col = 0; col<points.size(); col++){
        A[0][col] = 1;
    }
    for (int row=1; row<points.size(); row++){
        for (int col=0; col<points.size(); col++){
            A[row][col] = points[col]/fact(row);
            points[col] = points[col] * points[col];
        }
    }

    std::vector<double> b(points.size()); //TODO: формирование свободных членов
    //...
    for (int i = 0; i<points.size(); i++){
        b[i] = 0;
    }
    b[1] = 1;
    return GaussMethod(A, b);
}