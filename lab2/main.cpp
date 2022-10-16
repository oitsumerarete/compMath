//
// Created by Мария on 14.10.2022.
//
#include <iostream>
#include <vector>
#include "../lab2/newtonian_interpolator.cpp"
int main() {
    std::vector<double> test_x(4), test_y(4);
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
    return 0;
}