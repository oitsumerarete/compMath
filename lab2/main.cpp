//
// Created by Мария on 14.10.2022.
//
#include <iostream>
#include <vector>
#include "../lab2/newtonian_interpolator.cpp"
#include "cmath"
int main() {
    /*std::vector<double> test_x(4), test_y(4);
    for (int i = 0; i < 4; i++) std::cin >> test_x[i];
    for (int i = 0; i < 4; i++) std::cin >> test_y[i];
    NewtonianInterpolator test(test_x, test_y);
    matrix table = test.div_diff(test_x, test_y);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++){
            std::cout << table[i][j] << " ";
        }
        std::cout << std::endl;

    }
    double res = test.interpolate(2);
    std::cout << res;
     */
    //интерполяция косинуса
    /*
    int n;
    double a,b;
    std::cin >> n;
    std::cin >> a >> b;
    double step0 = (b-a)/(n-1);
    std::vector<double> test_x(n), test_y(n);
    for (int i = 0; i < n; i++) {
        test_x[i] = a + i*step0;
        test_y[i] = cos(test_x[i]);
    }

    NewtonianInterpolator he(test_x, test_y);
    double max_mistake = 0;
    double step = (b-a)/999;
    std::vector<double> x_int(1000), y_int(1000);
    for(int i = 0; i<1000; i++){
        x_int[i] = a + i*step;
        y_int[i] = cos(x_int[i]);
        if (fabs(he.interpolate(x_int[i]) - cos(x_int[i])) > max_mistake)
            max_mistake = fabs(he.interpolate(x_int[i]) - cos(x_int[i]));

    }
    std::cout << max_mistake << std::endl;
    */
    /*
    std::vector<double> x_cheb(5), y_cheb(5);
    double a,b;
    double pi = 3.141592653589793238463;
    std::cin >> a >> b;
    for (int i = 0; i < 5; i++) {
        x_cheb[i] = (a + b) / 2 + (b - a) / 2 * cos((2 * double(i+1) - 1) / 10 * pi);
        y_cheb[i] = cos(x_cheb[i]);
    }
    NewtonianInterpolator che(x_cheb, y_cheb);
    double max_mistake = 0;
    double step = (b-a)/999;
    std::vector<double> x_int(1000), y_int(1000);
    for(int i = 0; i<1000; i++){
        x_int[i] = a + i*step;
        y_int[i] = cos(x_int[i]);
        if (fabs(che.interpolate(x_int[i]) - cos(x_int[i])) > max_mistake)
            max_mistake = fabs(che.interpolate(x_int[i]) - cos(x_int[i]));

    }
    std::cout << max_mistake << std::endl;
    */
    // x^5 интерполянтом 6 степени
    int n = 6;
    double a = 0,b = 1000;
    double step0 = (b-a)/(n-1);
    std::vector<double> test_x(n), test_y(n);
    for (int i = 0; i < n; i++) {
        test_x[i] = a + i*step0;
        test_y[i] = test_x[i]*test_x[i]*test_x[i]*test_x[i]*test_x[i];
    }

    NewtonianInterpolator he(test_x, test_y);
    double max_mistake = 0;
    double step = (b-a)/999;
    std::vector<double> x_int(1000), y_int(1000);
    for(int i = 0; i<1000; i++){
        x_int[i] = a + i*step;
        y_int[i] = x_int[i]*x_int[i]*x_int[i]*x_int[i]*x_int[i];
        if (fabs(he.interpolate(x_int[i]) - x_int[i]*x_int[i]*x_int[i]*x_int[i]*x_int[i]) > max_mistake)
            max_mistake = fabs(he.interpolate(x_int[i]) - x_int[i]*x_int[i]*x_int[i]*x_int[i]*x_int[i]);

    }
    std::cout << max_mistake << std::endl;
    matrix table = he.div_diff(test_x, test_y);
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++){
            std::cout << table[i][j] << " ";
        }
        std::cout << std::endl;

    }
    return 0;

}