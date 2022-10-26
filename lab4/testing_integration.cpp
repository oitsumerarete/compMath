//
// Created by Мария on 25.10.2022.
//
#include <iostream>
#include "integration.h"

double func(double x) {
    return cos(x);
}

int main(){

    std::vector<int> steps(100);
    std::vector<double> mistakes_3(100);
    std::vector<double> mistakes_4(100);
    std::vector<double> mistakes_5(100);
    for(int i = 0; i < 100; i++)
    {
        steps[i] = i;
        mistakes_3[i] = fabs(integrate(0, 10, 3, i, func) - sin(10));
        mistakes_4[i] = fabs(integrate(0, 10, 4, i, func) - sin(10));
        mistakes_5[i] = fabs(integrate(0, 10, 5, i, func) - sin(10));

    }
    /*std::cout <<  "           3          " << "4         " << "5 " << std::endl;
    for (int i = 0; i < steps.size(); i++)
    {
        std::cout << steps[i] + 1 << " " << " " << mistakes_3[i] << " " << mistakes_4[i] << " " << mistakes_5[i] << std::endl;
    }*/
    for (int i = 0; i < steps.size(); i++)
    {
        std:: cout << mistakes_4[i] << std::endl;
    }
    return 0;
}