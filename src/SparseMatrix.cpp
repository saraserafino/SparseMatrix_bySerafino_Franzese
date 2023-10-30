#include "SparseMatrix.hpp"
#include <iostream>
#include <algorithm> // for using max_element

// Constructor
SparseMatrix::SparseMatrix(std::vector<double>& values, std::vector<unsigned int>& columns)
: values{values}, columns{columns} {}

// returns the number of non-zero elements
unsigned int SparseMatrix::get_num_nnz() const {
    return values.size();
    }

// returns the number of columns of the matrix. For the way it's saved, the number
// of columns is the maximum index of column of the non-zero values + 1
unsigned int SparseMatrix::get_num_columns() const {
    return values.empty() ? 0 : (*std::max_element(columns.begin(), columns.end()) + 1);
}