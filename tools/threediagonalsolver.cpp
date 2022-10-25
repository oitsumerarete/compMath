//
// Created by Мария on 24.10.2022.
//

#include "threediagonalsolver.h"
//реализация метода прогонки
std::vector<double> ThreeDiagonalSolver(matrix A, std::vector<double> b) {
    double y;
    if (A.size() == 0 || A.size() != b.size()) {std::cout << "null matrix" << '\n'; return std::vector<double>(0);}
    int n = static_cast<int>(b.size());

    std::vector<double> a(n-1), B(n-1);
    y = A[0][0];
    a[0] = - A[0][1]/y;
    B[0] = b[0]/y;
    for (int i = 1; i< n-1; i++){
        y = A[i][i] + A[i][i-1]*a[i-1];
        a[i] = -A[i][i+1]/y;
        B[i] = (b[i]-A[i][i-1]*B[i-1])/y;
    }
    std::vector<double> res(n);
    res[n-1] = (b[n-1]-A[n-1][n-2]*B[n-2])/(A[n-1][n-1]+A[n-1][n-2]*a[n-2]);
    for (int i = n-2; i>=0; i--)
        res[i]= a[i]*res[i+1]+B[i];
    return res;



}