//
// Created by Мария on 22.10.2022.
//

#include "integration.h"

/*** Функция для интегрирования на ожном отрезке
* a - начало отезка
* b - конец отрезка
* n - количество точек для квадратуры
* func - функция для интегрирования
***/
[[nodiscard]] double integrateOneSeg(
        double a,
        double b,
        unsigned n,
        const std::function<double(double)> & func) noexcept {
        double I=0;
        std::vector<double> x(n), ksi, omega(n);
        if (n==3) {
            x = {(-1)*sqrt(double(3) / 5), 0, sqrt(double(3) / 5)};
            omega = {5.0/9, 8.0/9, 5.0/9};
        }
        else if (n==4){
            x = {(-1)*sqrt(double(3)/7+double(2)/7*sqrt(double(6)/5)), -sqrt(double(3)/7 - double(2)/7*sqrt(double(6)/5)),
                 (-1)*x[1], x[0]*(-1)};
            omega = {(18-sqrt(30))/36, (18+sqrt(30))/36, (18+sqrt(30))/36, (18-sqrt(30))/36};
        }
        else if (n==5){
            x = {double((-1))/3*sqrt(5+2*sqrt(double(10)/7)), double((-1))/3*sqrt(5-2*sqrt(double(10)/7)), 0,
                 double(1)/3*sqrt(5-2*sqrt(double(10)/7)), double(1)/3*sqrt(5+2*sqrt(double(10)/7))};
            omega = {double(322-13*sqrt(70))/900, double(322+13*sqrt(70))/900, double(128)/225, double(322+13*sqrt(70))/900,
                     double(322-13*sqrt(70))/900};
        }

        for (int i = 0; i<n; i++) {
            x[i] = (b + a) / 2 + (b - a) / 2 * x[i];
            I+=func(x[i])*omega[i];
        }
        I = I*(b-a)/2;
        return I;
    }

double integrate(
        double a,
        double b,
        unsigned n,
        unsigned s,
        const std::function<double(double)> & func)
{
    double I = 0;
    for(int i = 0; i < s; i++)
    {
        I += integrateOneSeg(a + ((b - a)*i)/s, a + (b - a)*(i + 1.)/s, n, func);
    }
    return I;
}

