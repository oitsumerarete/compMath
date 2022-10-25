//
// Created by Мария on 19.10.2022.
//

#include "cubic_spline_wiki.h"
#include <vector>

class CubicSpline {
    /*** Какие-то поля ***/
private:
    unsigned int size;
    vec x,y;
    vec S_a, S_b, S_c, S_d;

public:

    /*** Конструктор, в котором строится кубический сплайн ***/
    explicit CubicSpline(const vec& xArr, const vec& yArr) {
        x = xArr;
        y = yArr;
        size = xArr.size()-1;
        vec a(size+1),b(size),c(size+1),d(size), h(size), alpha(size), l(size+1), m(size+1),z(size+1);

        for (int i = 0; i< size; i++)
            h.push_back(x[i+1] - x[i]);

        a.insert(a.begin(), y.begin(), y.end());

        alpha.push_back(0);
        for(int i = 1; i < size; i++)
            alpha.push_back( 3*(a[i+1]-a[i])/h[i] - 3*(a[i]-a[i-1])/h[i-1] );

        l.push_back(1);
        m.push_back(0);
        z.push_back(0);
        for (int i = 1; i < size; i++) {
            l.push_back(2 * (x[i + 1] - x[i - 1]) - h[i - 1] * m[i - 1]);
            m.push_back(h[i] / l[i]);
            z.push_back((alpha[i] - h[i - 1] * z[i - 1]) / l[i]);
        }
        l.push_back(1);
        z.push_back(0);
        c.push_back(0);
        unsigned int j = size - 1;
        while(j>0){
            c[j] = z[j] - m[j]*c[j+1];
            b[j] = (a[j+1]-a[j])/h[j]-h[j]*(c[j+1]+2*c[j])/3;
            d[j] = (c[j+1]-c[j])/3/h[j];
            j--;
        }
        S_a = a;
        S_b = b;
        S_c = c;
        S_d = d;

    }

    /*** Метод, выполняющий подсчет интерполянта в точке ***/
    [[nodiscard]] double interpolate(double x0) const {
        for (int i = 1; i < size; i++) {
            if (x0 < x[i]) {
                return (S_a[i] + S_b[i] * (x0 - x[i]) + S_c[i] * (x0 - x[i]) * (x0 - x[i]) +
                 S_d[i] * (x0 - x[i]) * (x0 - x[i]) * (x0 - x[i]));
            }
        }
        throw std::exception();
    }

};
