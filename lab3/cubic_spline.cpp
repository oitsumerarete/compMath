//
// Created by Мария on 24.10.2022.
//

#include "cubic_spline.h"
#include "../tools/threediagonalsolver.h"
#include <vector>
#include "cmath"

class CubicSpline {
    /*** Какие-то поля ***/
private:
    unsigned int size;
    std::vector<double> x, y, a1,c1;
    std::vector<double> b1, d1;
    matrix he;
public:

    /*** Конструктор, в котором строится кубический сплайн ***/
    explicit CubicSpline(const std::vector<double>& xArr, const std::vector<double>& yArr){
        size = xArr.size();
        x = xArr;
        y = yArr;
        b1 = std::vector<double>(size - 1);
        d1 = std::vector<double>(size - 1);
        std::vector<double>a(size-1), b(size-1), c(size-1), d(size-1), f_1(size-1), f_2(size-2  );
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
                A[i][i - 1] = h[i] / (h[i] + h[i + 1]);
                A[i][i + 1] = h[i + 1] / (h[i] + h[i + 1]);
                A[i][i] = 2;
            }
            A[size - 3][size - 4] = h[size - 3] / (h[size - 3] + h[size - 2]);
            A[size - 3][size - 3] = 2;
        }

        f_1[0] = (y[1] - y[0]) / h[0];
        for (int i = 2; i < size; i++) {
            f_1[i - 1] = (y[i] - y[i - 1]) / h[i - 1];
            f_2[i - 2] = (f_1[i-1] - f_1[i - 2]) / (h[i - 2] + h[i-1]);
        }

        std::vector<double> f_20(size -2);
        for (int i = 0; i < size -2; i++)
            f_20[i] = 6 * f_2[i];
        c = ThreeDiagonalSolver(A, f_20);
        c[size-2] = 0;

        b[0] = ((c[0] * h[0]) / 3) + f_1[0];
        d[0] = c[0] / h[0];
        for (int i = 1; i < size - 1; i++) {
            b[i] = ((c[i] * h[i]) / 3) + ((c[i-1] * h[i]) / 6) + f_1[i];
            d[i] = (1 / h[i]) * (c[i] - c[i - 1]);
        }

        for (int i = 0; i<y.size()-1; i++)
            a[i] = y[i+1];
        a1 = a;
        c1 = c;
        he = A;
        b1 = b;
        d1 = d;
    }

    /*** Метод, выполняющий подсчет интерполянта в точке ***/
    [[nodiscard]] double interpolate(double x0) const{
        for (int i = 0; i < size; i++) {
            if (x0 < x[i] && i != 0) {
                const double arg = (x0 - x[i]);
                const double arg2 = arg * arg;
                const double arg3 = arg2 * arg;
                return a1[i-1] + b1[i-1] * arg + (c1[i-1]/2) * arg2 + (d1[i-1]/6) * arg3;
            }
        }
        throw std::exception();
    }
    matrix help(){
        return he;
    }
};