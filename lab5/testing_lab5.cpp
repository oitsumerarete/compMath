//
// Created by Мария on 16.11.2022.
//

#include <iostream>
#include "dikhotomy.h"
double pi =  3.1415926535;
double func1(double x) {
    return (x-0.1*sin(x)-pi/4);
}
double func2(double x){
    return (tan(x) - 4*x/pi);
}
int main(){
    std::cout << "bisection method for first" << std::endl;
    for (unsigned i = 1; i<100; i++){
    double res = bisectionMethod(0, 10, func1, i);
    std::cout << std::abs(res-0.1*sin(res)-pi/4) << std::endl;
    }
    std::cout << "bisection method for second" << std::endl;
    for (unsigned i = 1; i<100; i++){
        double res = bisectionMethod(0, 10, func2, i);
        std::cout << std::abs(tan(res) - 4*res/pi) << std::endl;
    }
    return 0;

}
