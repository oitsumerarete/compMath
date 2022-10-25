//
// Created by Мария on 20.10.2022.
//
#include <iostream>
#include "cubic_spline.cpp"
#include "../tools/threediagonalsolver.h"
#include "cmath"
int main(){

    int b =3;
    int points = 6;
    double max_mistake = 0;

    while(points < 130) {
        std::vector<double> x_points(points), y_points(points), x_int(1000), y_int(1000);
        for (int i = 0; i < points; i++) {
            x_points[i] = double(i) * b / (points - 1);
            y_points[i] = cos(x_points[i]);
        }
        CubicSpline he(x_points, y_points);
        for (int i = 0; i < 999; i++) {
            x_int[i] = double(i) * b / 999;
            y_int[i] = cos(x_int[i]);
            if (fabs(he.interpolate(x_int[i]) - cos(x_int[i])) > max_mistake)
                max_mistake = fabs(he.interpolate(x_int[i]) - cos(x_int[i]));
        }
        std::cout << points << " points, mistake = " << max_mistake << ' ';
        points = points*2;
        max_mistake = 0;
        x_points.clear();
        y_points.clear();
    }

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