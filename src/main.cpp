#include "SparseMatrix.hpp"
#include "SparseMatrixCOO.hpp"
#include "SparseMatrixCSR.hpp"
#include "converter.hpp"
#include <iostream>

bool check_matrix_vector_product(std::vector<double> matrix) {
    std::vector<int> vector1(size_rows, 1); // initialize the vector of 1 with lenght the number of rows of the matrix
    // Calculate the sum of the i-th row of the matrix
    for (unsigned int i = 0; i < size_rows; ++i) {
        std::vector<double> sum_rows[i] = 0; // initializate the result to 0
        for (unsigned int j = 0; j < size_columns; ++j) {
            sum_rows[i] += A[i,j];
        }
    }
    // If correct, the matrix-vector product must give the sum of the i-th row
    if (matrix*vector1 != sum_rows) {
        return false; // The matrix-vector product doesn't work well
    }
    return true; // The matrix-vector product works well!
}

int main () {
    // Let's run some tests to validate the correctness of the program
    
    std::cout << "Does the matrix-vector product work well?" << check_matrix_vector_product(matrix) << std::endl;
    return 0;
}
