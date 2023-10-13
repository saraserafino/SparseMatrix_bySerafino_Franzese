#include "SparseMatrix.hpp"
#include "SparseMatrixCOO.hpp"
#include "SparseMatrixCSR.hpp"
#include "converter.hpp"
#include <iostream>

int main () {
    // Let's run some tests to validate the correctness of the program
    
    // Given a vector of 1, the matrix-vector product must give the sum of the i-th row
    std::vector<int> vector1(size_rows, 1); // initialize the vector of 1 with lenght the number of rows of the matrix
    for (unsigned int i = 0; i < size_rows; ++i) {
        std::vector<double> sum_rows[i] = 0; // initializate the result to 0
        for (unsigned int j = 0; j < size_columns; ++j) {
            sum_rows[i] += sum_rows[j-1]
        }
    }
    if (matrix*vector1 == sum_rows) {
        std::cout << "The matrix-vector product works well!" << std::endl;
    }
    else {
        std::cout << "The matrix-vector product doesn't work well." << std::endl;
    }
    return 0;
}
