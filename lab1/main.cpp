//
// Created by Мария on 26.09.2022.
//
#include <iostream>
#include <fstream>
#include <vector>
#include "diff_scheme_uc.h"
#include "cmath"
#include "../lab2/newtonian_interpolator.cpp"

int main() {

    std::vector<double> nodes = {-2, -1, 0, 1, 2};
    std::vector<double> res = firstDer(nodes);
    for (double re : res){
        std::cout << re << " ";
    }
    std::cout << std::endl;
    double x0 = 3.141592653589793238463;
    double h = 0.00000001;
    double proizv = 0;
    double proizv0 = pow(3.141592653589793238463, 3.141592653589793238463)*(std::log(3.141592653589793238463) + 1);
    std::cout << proizv0 << std::endl;

    std::ofstream lab1_data("data.csv");

    while (h<0.01) {
        for (int i = 0; i < nodes.size(); i++)
            proizv += pow((x0 + nodes[i] * h), (x0 + nodes[i] * h)) * res[i] / h;
        std::cout << "Epsilon: " << fabs(proizv - proizv0) << " step h = " << h << std::endl;
        lab1_data << fabs(proizv - proizv0) << " " << h << "\n";
        h=h*4;
        proizv = 0;
    }
    while (h<1) {
        for (int i = 0; i < nodes.size(); i++)
            proizv += pow((x0 + nodes[i] * h), (x0 + nodes[i] * h)) * res[i] / h;
        std::cout << "Epsilon: " << fabs(proizv - proizv0) << " step h = " << h << std::endl;
        lab1_data << fabs(proizv - proizv0) << " " << h << "\n";
        h=h+0.1;
        proizv = 0;
    }
    //std::cout << std::endl << proizv;
    lab1_data.close();
    return 0;


}
