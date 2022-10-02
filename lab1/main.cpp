//
// Created by Мария on 26.09.2022.
//
#include <iostream>
#include <vector>
#include <string>
#include "diff_scheme_uc.h"
#include "../tools/gauss_method.h"

int main() {
    std::vector<double> nodes;
    nodes = {0, -1};
    std::vector<double> res = firstDer(nodes);
    for (int i = 0; i < res.size(); i++){
        std::cout << res[i] << " ";
    }
    return 0;

}
