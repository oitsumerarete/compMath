//
// Created by Мария on 26.09.2022.
//
#include <iostream>
#include <vector>
#include "diff_scheme_uc.h"


int main() {
    std::vector<double> nodes = {-1, 0, 1};
    std::vector<double> res = firstDer(nodes);
    for (double re : res){
        std::cout << re << " ";
    }
    return 0;

}
