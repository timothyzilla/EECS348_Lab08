#include "matrix_operations.h"
#include <iostream>
#include <fstream>

bool read_matrix_from_file(const std::string &filename, std::vector<std::vector<int>> &matrix1, std::vector<std::vector<int>> &matrix2) {
    std::ifstream file(filename);
    if (!file) return false;

    int N;
    file >> N;
    matrix1.resize(N, std::vector<int>(N));
    matrix2.resize(N, std::vector<int>(N));

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            file >> matrix1[i][j];

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            file >> matrix2[i][j];

    return true;
}

void print_matrix(const std::vector<std::vector<int>> &matrix) {
    for (const auto &row : matrix) {
        for (int num : row)
            std::cout << num << " ";
        std::cout << std::endl;
    }
}

std::vector<std::vector<int>> add_matrices(const std::vector<std::vector<int>> &matrix1, const std::vector<std::vector<int>> &matrix2) {
    int N = matrix1.size();
    std::vector<std::vector<int>> result(N, std::vector<int>(N));

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            result[i][j] = matrix1[i][j] + matrix2[i][j];

    return result;
}

std::vector<std::vector<int>> multiply_matrices(const std::vector<std::vector<int>> &matrix1, const std::vector<std::vector<int>> &matrix2) {
    int N = matrix1.size();
    std::vector<std::vector<int>> result(N, std::vector<int>(N, 0));

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            for (int k = 0; k < N; ++k)
                result[i][j] += matrix1[i][k] * matrix2[k][j];

    return result;
}

int sum_of_diagonals(const std::vector<std::vector<int>> &matrix) {
    int N = matrix.size(), sum = 0;
    for (int i = 0; i < N; ++i) {
        sum += matrix[i][i]; // Main diagonal
        if (i != N - i - 1) sum += matrix[i][N - i - 1]; // Secondary diagonal
    }
    return sum;
}

void swap_rows(std::vector<std::vector<int>> &matrix, int row1, int row2) {
    if (row1 >= 0 && row2 >= 0 && row1 < (int)matrix.size() && row2 < (int)matrix.size())
        std::swap(matrix[row1], matrix[row2]);
}

void swap_columns(std::vector<std::vector<int>> &matrix, int col1, int col2) {
    if (!matrix.empty() && col1 >= 0 && col2 >= 0 && col1 < (int)matrix[0].size() && col2 < (int)matrix[0].size()) {
        for (auto &row : matrix)
            std::swap(row[col1], row[col2]);
    }
}

void update_matrix_element(std::vector<std::vector<int>> &matrix, int row, int col, int new_value) {
    if (row >= 0 && col >= 0 && row < (int)matrix.size() && col < (int)matrix[0].size())
        matrix[row][col] = new_value;
}
