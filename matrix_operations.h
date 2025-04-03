#ifndef MATRIX_OPERATIONS_H
#define MATRIX_OPERATIONS_H

#include <vector>
#include <string>

// Function to read a matrix from a file
bool read_matrix_from_file(const std::string &filename, std::vector<std::vector<int>> &matrix1, std::vector<std::vector<int>> &matrix2);

// Function to print a matrix
void print_matrix(const std::vector<std::vector<int>> &matrix);

// Function to add two matrices
std::vector<std::vector<int>> add_matrices(const std::vector<std::vector<int>> &matrix1, const std::vector<std::vector<int>> &matrix2);

// Function to multiply two matrices
std::vector<std::vector<int>> multiply_matrices(const std::vector<std::vector<int>> &matrix1, const std::vector<std::vector<int>> &matrix2);

// Function to calculate the sum of diagonal elements
int sum_of_diagonals(const std::vector<std::vector<int>> &matrix);

// Function to swap two rows
void swap_rows(std::vector<std::vector<int>> &matrix, int row1, int row2);

// Function to swap two columns
void swap_columns(std::vector<std::vector<int>> &matrix, int col1, int col2);

// Function to update a specific matrix element
void update_matrix_element(std::vector<std::vector<int>> &matrix, int row, int col, int new_value);

#endif
