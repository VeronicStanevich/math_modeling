#include <iostream>
#include <vector>
#include "algoritms/Gauss.h"
#include "factory/dataFactory.h"

int main() {
    int size;
    std::cout << "Введите размерность матрицы:" << std::endl;
    std::cin >> size;
    try {
        std::vector<std::vector<double>> matrix = getMatrixRand(size);
//        std::vector<std::vector<double>> matrix = getMatrix();
        std::vector<std::vector<double>> defaultMatrix = copyMatrix(matrix);
        std::vector<double> solutions = getSolutionsRand(size);
        std::vector<double> x = evaluateByGauss(matrix, solutions);
        std::cout << "Матрица после преобразования:" << std::endl;
        for (auto itemI: matrix) {
            for (auto itemJ: itemI) {
                std::cout << itemJ << ' ';
            }
            std::cout << std::endl;
        }
        std::cout << "Полученые значения х:";
        for (auto solution: x) {
            std::cout << std::endl << solution;
        }

        std::cout << std::endl;
        std::cout << std::endl;

        std::cout << "Невязка:" << std::endl;
        for (int i = 0; i < defaultMatrix.size(); i++) {
            double sum = 0;
            for (int j = 0; j < defaultMatrix[i].size(); j++) {
                sum += defaultMatrix[i][j] * x[j];
            }
            std::cout << (sum - solutions[i]) << std::endl;
        }
    } catch (const std::invalid_argument &e) {
        std::cout << e.what();
    }

    return 0;
}

