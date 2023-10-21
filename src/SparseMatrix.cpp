#include "SparseMatrix.hpp"
#include <iostream>

// Constructor
SparseMatrix::SparseMatrix(const unsigned int &input_size_rows, const unsigned int &input_size_columns):
size_rows(input_size_rows), size_columns(input_size_columns) {
    nnz = 0;
    // se facciamo vettore di vettore usiamo questo:
    lunghezza = size_rows * size_columns;
    }
    
//copy costructor
SparseMatrix::SparseMatrix(const SparseMatrix &other) {
    matrix = new double[other.lunghezza];
    size_columns = other.size_columns;
    size_rows = other.size_rows;
    lunghezza = other.lunghezza;
    // il seguente penso dia problemi per il fatto che ci sono gli 0 non dichiarati, casomai da dire che se non c'è è 0
    for (unsigned int i=0; i< lunghezza; i++){
        matrix[i]= other.matrix[i];
    }
    }

