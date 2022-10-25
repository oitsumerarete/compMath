//
// Created by Мария on 24.10.2022.
//

#include "cubic_spline.h"
#include "../tools/threediagonalsolver.h"
#include <vector>

class CubicSpline {
    /*** Какие-то поля ***/
private:
    int size;
    std::vector<double> x, a1,c1;
    std::vector<double> b1, d1;
    matrix he;
public:

    /*** Конструктор, в котором строится кубический сплайн ***/
    explicit CubicSpline(const std::vector<double>& xArr, const std::vector<double>& yArr)noexcept{
        size = static_cast<int>(xArr.size());
        x = xArr;
        std::vector<double>a(size-1), b(size-1), c(size-1), d(size-1), f_1(size-1), f_2(size-2);
        std::vector<double>h(size-1);


        for (int i = 1; i<size; i++)
            h[i-1] = x[i] - x[i-1];

        matrix A(size-2);
        for (int i = 0; i<size-2; i++)
            A[i].resize(size-2);

        if (size > 2) {
            A[0][0] = 2;
            A[0][1] = h[1] / (h[1] + h[0]);

            for (int i = 1; i < size - 3; i++) {
                A[i][i - 1] = h[i-1] / (h[i] + h[i+1]);
                A[i][i + 1] = h[i+1] / (h[i] + h[i+1]);
                A[i][i] = 2;
            }
            A[size - 3][size - 4] = h[size - 3] / (h[size - 3] + h[size - 2]);
            A[size - 3][size - 3] = 2;


        f_1[0] = (yArr[1] - yArr[0]) / h[0];
        for (int i = 2; i < size; i++) {
            f_1[i - 1] = (yArr[i] - yArr[i - 1]) / h[i - 1];
            f_2[i - 2] = (f_1[i-1] - f_1[i - 2]) / (h[i-2] + h[i-1]);
        }

        std::vector<double> f_20(size-2);
        for (int i = 0; i < size -2; i++)
            f_20[i] = 6 * f_2[i];
        c = ThreeDiagonalSolver(A, f_20);
        }
        c[size-2] = 0;

        b[0] = f_1[0] + (c[0]*h[0]/3);
        d[0] = c[0]/h[0];
        for (int i = 1; i < size - 1; i++) {
            b[i] = ((c[i] * h[i]) / 3) + ((c[i-1] * h[i]) / 6) + f_1[i];
            d[i] = (1 / h[i]) * (c[i] - c[i - 1]);
        }
        if (size == 2) {
            b = {h[0], h[1]};
            d = {0,0};
            c = {0,0};
        }

        std::copy(yArr.begin() + 1, yArr.begin() + size, a.begin());
        a1 = a;
        c1 = c;
        he = A;
        b1 = b;
        d1 = d;
    }

    /*** Метод, выполняющий подсчет интерполянта в точке ***/
    [[nodiscard]] double interpolate(double x0) const{
        if (size>2){
        for (int i = 0; i < size; i++) {
            if (x0 < x[i] && i != 0) {
                const double arg = (x0 - x[i]);
                const double arg2 = arg * arg;
                const double arg3 = arg2 * arg;
                return a1[i-1] + b1[i-1] * arg + (c1[i-1]/2) * arg2 + (d1[i-1]/6) * arg3;
            }
        }
            }
        else {
            return a1[0] + b1[0]*(x0 - x[1]) + (c1[0]/2) * (x0 - x[1])* (x0 - x[1]) + (d1[0]/6)*(x0 - x[1]) * (x0 - x[1]) * (x0 - x[1]);
        }
        throw std::exception();
    }

    matrix help(){
        return he;
    }
};