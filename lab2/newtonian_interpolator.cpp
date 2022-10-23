//
// Created by Мария on 11.10.2022.
//

#include <vector>
#include "../tools/gauss_method.h"
class NewtonianInterpolator {
    /*** Какие-то поля ***/
private:
    unsigned int size;
    std::vector<double> dataX;
    std::vector<double> dataY;
public:

    /*** Конструктор по массиву аргументов и значений функции ***/
    explicit NewtonianInterpolator(
            const std::vector<double> &x,
            const std::vector<double> &y) {
    size = x.size();
    dataX = x;
    dataY = y;
    }
    [[nodiscard]] matrix div_diff(const std::vector<double> &x, const std::vector<double> &y) const {
        matrix difference(size);
        for (int i = 0; i < size; i++)
            difference[i].resize(size);
        for (int i = 0; i < size; i++) difference[i][0] = y[i];
        int dValue = 1;
        for (int i = 0; i < size-1; i++) {
            for (int j = i; j < size-1; j++) {
                difference[j + 1][i + 1] = (difference[j + 1][i] - difference[j][i]) / (x[j + 1] - x[j + 1 - dValue]);
            }
            dValue++;
        }
        return difference;
    }
    /*** Метод, выполняющий подсчет интерполяционного полинома в точке ***/
    [[nodiscard]] double interpolate(double x) const {
        double calcValue = 0;
        matrix dTable = div_diff(dataX, dataY);
        for (int i = 0; i < size; i++) {
            double tmp = 1;
            for (int j = 0; j < i; j++)
                tmp *= x - dataX[j];
            tmp *= dTable[i][i];
            calcValue += tmp;
        }
        return calcValue;
    }


};
