#include <iostream>
#include "matrix_operations.h"

int main() {
    std::string filename;
    std::cout << "Enter the matrix file name: ";
    std::cin >> filename;

    std::vector<std::vector<int>> matrix1, matrix2;

    // Read matrices from file
    if (!read_matrix_from_file(filename, matrix1, matrix2)) {
        std::cerr << "Error reading file!" << std::endl;
        return 1;
    }

    std::cout << "Matrix 1:\n";
    print_matrix(matrix1);
    
    std::cout << "Matrix 2:\n";
    print_matrix(matrix2);

    // Add matrices
    std::cout << "\nAdding Matrices...\n";
    print_matrix(add_matrices(matrix1, matrix2));

    // Multiply matrices
    std::cout << "\nMultiplying Matrices...\n";
    print_matrix(multiply_matrices(matrix1, matrix2));

    // Sum of diagonals
    std::cout << "\nSum of Diagonals: " << sum_of_diagonals(matrix1) << std::endl;

    // Swap rows
    std::cout << "\nSwapping Rows (0 and 1)...\n";
    swap_rows(matrix1, 0, 1);
    print_matrix(matrix1);

    // Swap columns
    std::cout << "\nSwapping Columns (0 and 1)...\n";
    swap_columns(matrix1, 0, 1);
    print_matrix(matrix1);

    // Update an element
    std::cout << "\nUpdating Element at (0,0) to 99...\n";
    update_matrix_element(matrix1, 0, 0, 99);
    print_matrix(matrix1);

    return 0;
}
