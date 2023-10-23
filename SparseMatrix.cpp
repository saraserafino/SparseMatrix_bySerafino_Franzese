#include "SparseMatrix.hpp"
#include <iostream>

// Constructor
SparseMatrix::SparseMatrix(std::vector<double>& values, std::vector<unsigned int>& columns)
: values{values}, columns{columns} {}

// returns the number of non-zero elements
unsigned int SparseMatrix::get_num_nnz() const {
    return values.size();
    }

// returns the number of columns of the matrix. For the way it's saved, the number of columns
// is the maximum index of column of the non-zero values
unsigned int SparseMatrix::get_num_columns() const {
    if (values.empty()) {
        return 0; // If there are no values, there is no column
    }
    return *std::max_element(columns.begin(), columns.end()) + 1;
}

/* Copy costructor
SparseMatrix::SparseMatrix(const SparseMatrix &other) {
    matrix = new double[other.lunghezza];
    size_columns = other.size_columns;
    size_rows = other.size_rows;
    lunghezza = other.lunghezza;
    // il seguente penso dia problemi per il fatto che ci sono gli 0 non dichiarati, casomai da dire che se non c'è è 0
    for (unsigned int i = 0; i < lunghezza; i++){
        matrix[i]= other.matrix[i];
    }
    }

void printmatrix() {
    // qui vogliamo stamparla (in modo univoco) dicendo che se non ci sono valori assegnati mette 0
}
*/
