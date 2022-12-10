//
// Created by Мария on 16.11.2022.
//

#include <iostream>
#include <cmath>
#include <vector>

#include "dikhotomy.h"
#include "simpleIteration.h"

double pi =  3.1415926535;

double func1(double x) {
    return (x-0.1*std::sin(x)-pi/4);
}
double func1_deriv(double x){
 //
}
//---------------------------
double func2(double x){
    return ((4 * x / pi) - std::tan(x));
}
double func2_deriv(double x){
    return (- 1/(std::cos(x) * std::cos(x)) + 4 / pi);
}
//-----------------------------
double func3(double x){
    return (std::log(std::cosh(x)));
}
double func3_deriv(double x){

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

    ///////////////////////////////
    /// SIMPLE ITERATION //////////
    ///////////////////////////////

    std::cout << "simple it method for second" << std::endl;

    for (unsigned i = 1; i < 500; i+=20){
        std::cout << std::endl;
        std::cout << "NUM OF ITERATIONS " << i << std::endl;
        double res = simpleIterationMethod(0.8, func2, 0.05, i);
        double error = calc_error(0.8, func2, func2_deriv, 0.05, i);

        std::cout << "error " << error << std::endl;
        std::cout << "res: " << res << " solution: " << std::abs(-tan(res) + 4 * res / pi) << std::endl;
        std::cout << std::endl;
    }




    return 0;
}
