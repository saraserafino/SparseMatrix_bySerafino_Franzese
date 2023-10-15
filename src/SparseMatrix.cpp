#include "SparseMatrix.hpp"
#include <iostream>

// The following class is an abstract class because there's at least one virtual method defined as pure virtual.
// Pure virtual functions act as placeholders for functionality that must be provided by derived classes.
// Here the derived classes are SparseMatrixCOO and SparseMatrixCSR
// They enforce a specific method signature that derived classes must adhere to.
class SparseMatrix { // abstract class
public:
    // Defining the pure virtual methods that _COO and _CSR have in common
    virtual int get_rows() = 0;
    virtual int get_columns() = 0;
    virtual int get_nonzeros() = 0;

    // Constructor
    SparseMatrix::SparseMatrix(const int &input_size_rows, const int &input_size_columns)
    : size_rows(input_size_rows), size_columns(input_size_columns), matrix(new double[size_rows][size_columns])
    {
    for (unsigned int i = 0; i < size_rows; ++i) {
            for (unsigned int j = 0; j < size_columns; ++j) {
                matrix[i][j] = 0;
            }
    }
    }

    // Copy constructor
    SparseMatrix::SparseMatrix(const SparseMatrix &other)
    : size_rows(other.size_rows), size_columns(other.size_columns), matrix(new double[size_rows][size_columns])
    {
    for (unsigned int i = 0; i < size_rows; ++i) {
            for (unsigned int j = 0; j < size_columns; ++j) {
                matrix[i][j] = other[i][j];
            }
    }
    };

    // Implement access and write matrix entries by overloading the operator ()
    SparseMatrix operator()(int &input_size_rows, int &input_size_columns) {
        SparseMatrix result;
        if (input_size_rows >= 0 && input_size_rows < size_rows && input_size_columns >= 0 && input_size_columns < size_columns)
        {
            return matrix[input_size_rows][input_size_columns];
        }
        else {
            std::cout << "Index out of bounds." << std::endl;
        }
        return result;
    }
};