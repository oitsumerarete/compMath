//
// Created by Мария on 20.10.2022.
//
#include <iostream>
#include "cubic_spline.cpp"
#include "../tools/threediagonalsolver.h"
#include "cmath"
int main(){
    /* ПРОСТИГОСПОДИ ОНО РАБОТАЕТ
    */double x0 = 0.95;
    std::vector<double> x = {0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1};
    std::vector<double> y = {0, 0.033, 0.067, 0.100, 0.134, 0.168, 0.203, 0.238, 0.273, 0.309, 0.346};
    CubicSpline interpolator(x,y);
    double res = interpolator.interpolate(x0);
    matrix check = interpolator.help();
    for (int i = 0; i < check.size(); i++){
            for (int j = 0; j < check.size(); j++){
                std::cout << check[i][j] << " ";
            }
            std::cout << std::endl;
        }
     std::cout << res;
/*

    int b =3;
    int points = 2;
    double max_mistake = 0;
    /*
    while(points < 130) {
        std::vector<double> x_points(points), y_points(points), x_int(1000), y_int(1000);
        for (int i = 0; i < points; i++) {
            x_points[i] = double(i) * b / (points - 1);
            y_points[i] = cos(x_points[i]);
        }
        CubicSpline he(x_points, y_points);
        for (int i = 0; i < 1000; i++) {
            x_int[i] = double(i) * b / 999;
            y_int[i] = cos(x_int[i]);
            if (fabs(he.interpolate(x_int[i]) - cos(x_int[i])) > max_mistake)
                max_mistake = fabs(he.interpolate(x_int[i]) - cos(x_int[i]));
        }
        std::cout << points << " points, mistake = " << max_mistake;
        points = points*2;
        x_points.clear();
        y_points.clear();

    }
*/
    /*
    std::vector<double> x_points(points), y_points(points), x_int(1000), y_int(1000);
    for (int i = 0; i < points; i++) {
        x_points[i] = double(i) * b / (points - 1);
        y_points[i] = cos(x_points[i]);
    }
    CubicSpline he(x_points, y_points);
    std::cout << he.interpolate(0);
    for (int i = 0; i < 1000; i++) {
        x_int[i] = double(i) * b / 999;
        y_int[i] = cos(x_int[i]);
        //std::cout << x_int[i] << " " << y_int[i] << std::endl;
    }
    */

    return 0;
}