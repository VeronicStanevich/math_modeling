#include "Gauss.h"
#include <iostream>
#include <cmath>
#include <stdexcept>

const double eps = 0.00001;

std::vector<double> evaluateByGauss(std::vector<std::vector<double>> &matrix, std::vector<double> solutions) {
    std::vector<double> x;
    int n = matrix.size();
    x.resize(n);
    double max;
    int k = 0, index;
    while (k < n) {
        // Поиск строки с максимальным a[i][k]
        max = std::abs(matrix[k][k]);
        index = k;
        for (int i = k + 1; i < n; i++) {
            if (abs(matrix[i][k]) > max) {
                max = abs(matrix[i][k]);
                index = i;
            }
        }
        // Перестановка строк
        if (max < eps) {
            // нет ненулевых диагональных элементов
            throw std::invalid_argument("Решение получить невозможно из-за нулевого столбца ");
        }
        for (int j = 0; j < n; j++) {
            double temp = matrix[k][j];
            matrix[k][j] = matrix[index][j];
            matrix[index][j] = temp;
        }
        double temp = solutions[k];
        solutions[k] = solutions[index];
        solutions[index] = temp;
        // Нормализация уравнений

        for (int i = k; i < n; i++) {
            double temp = matrix[i][k];
            if (abs(temp) < eps) continue; // для нулевого коэффициента пропустить
            for (int j = 0; j < n; j++)
                matrix[i][j] = matrix[i][j] / temp;
            solutions[i] = solutions[i] / temp;
            if (i == k) continue; // уравнение не вычитать само из себя
            for (int j = 0; j < n; j++)
                matrix[i][j] = matrix[i][j] - matrix[k][j];
            solutions[i] = solutions[i] - solutions[k];
        }
        k++;
    }
    // обратная подстановка

    for (k = n - 1; k >= 0; k--) {
        x[k] = solutions[k];
        for (int i = 0; i < k; i++)
            solutions[i] = solutions[i] - matrix[i][k] * x[k];
    }
    return x;
}