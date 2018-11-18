#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

std::string inputAnsFilePath = "/Users/admin/CLionProjects/gauss/untitled1/factory/matrix_ans.csv";
std::string matrixFilePath = "/Users/admin/CLionProjects/gauss/untitled1/factory/matrix.csv";

std::vector<std::string> explode(const std::string &delimiter, const std::string &str) {
    std::vector<std::string> arr;
    int strleng = str.length();
    int delleng = delimiter.length();
    if (delleng == 0)
        return arr;//no change

    int i = 0;
    int k = 0;
    while (i < strleng) {
        int j = 0;
        while (i + j < strleng && j < delleng && str[i + j] == delimiter[j])
            j++;
        if (j == delleng)//found delimiter
        {
            arr.push_back(str.substr(k, i - k));
            i += delleng;
            k = i;
        } else {
            i++;
        }
    }
    arr.push_back(str.substr(k, i - k));
    return arr;
}

std::vector<double> getSolutions() {
    try {
        std::ifstream inputFileStream(inputAnsFilePath, std::ios::in);
        std::string line;
        std::vector<std::string> read;

        while (std::getline(inputFileStream, line)) {
            read = explode(",", line);
        }

        std::vector<double> ans;
        ans.reserve(read.size());
        for (const auto &str: read) {
            ans.push_back(std::stod(str));
        }

        return ans;
    } catch (std::exception& e) {
        throw std::invalid_argument("Невозможно прочитать файл y");
    }
}

std::vector<double> getSolutionsRand(int n) {
    std::vector<double> ans;
    ans.reserve(n);
    for (int i = 0; i < n; i++) {
        ans.push_back(rand() % 10);
    }

    return ans;
}

std::vector<std::vector<double>> getMatrix() {
    try {
        std::vector<std::vector<double>> matrix;
        std::ifstream inputFileStream(matrixFilePath, std::ios::in);
        std::string line;

        for (int i = 0; std::getline(inputFileStream, line); i++) {
            matrix.emplace_back();
            std::vector<std::string> lineVector = explode(",", line);

            for (const std::string &str: lineVector) {
                matrix[i].push_back(std::stod(str));
            }
        }

        return matrix;
    } catch (std::exception& e) {
        throw std::invalid_argument("Невозможно прочитать файл");
    }
}

std::vector<std::vector<double>> getMatrixRand(int n) {
    std::vector<std::vector<double>> matrix;
    for (int i = 0; i < n; i++) {
        std::vector<double> vec;
        for (int j = 0; j < n; j++) {
            vec.push_back(rand() % 10);
        };
        matrix.push_back(vec);
    }
    return matrix;
}

std::vector<std::vector<double>> copyMatrix(std::vector<std::vector<double>> matrix) {
    std::vector<std::vector<double>> matrixCopy;
    for (int i = 0; i < matrix.size(); i++) {
        std::vector<double> vec;
        for (int j = 0; j < matrix[i].size(); j++) {
            double value = matrix[i][j];
            vec.push_back(value);
        }
        matrixCopy.push_back(vec);
    }
    return matrixCopy;
}