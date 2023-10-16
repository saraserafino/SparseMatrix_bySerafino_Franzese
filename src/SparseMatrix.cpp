#include "SparseMatrix.hpp"
#include <iostream>

// The following class is an abstract class because there's at least one virtual method defined as pure virtual.
// Pure virtual functions act as placeholders for functionality that must be provided by derived classes.
// Here the derived classes are SparseMatrixCOO and SparseMatrixCSR
// They enforce a specific method signature that derived classes must adhere to.


    // Constructor
    SparseMatrix::SparseMatrix(const int input_size_rows, const int input_size_columns)
    {
        this->size_rows = input_size_rows;
        nnz = 0;
        this->size_columns = input_size_columns;
        lunghezza = size_rows*size_columns;

    for (unsigned int i = 0; i < lunghezza; i++) {
            matrix[i] = 0;
        }
    }
    
   //copy costructor
    SparseMatrix::SparseMatrix(const SparseMatrix &other){
    matrix = new double[other.lunghezza];
    size_columns = other.size_columns;
    size_rows = other.size_rows;
    lunghezza = other.lunghezza;
    for (unsigned int i=0; i< lunghezza; i++){
        matrix[i]= other.matrix[i];
    }
    }


