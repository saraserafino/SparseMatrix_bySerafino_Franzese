#ifndef SPARSE_MATRIX_HPP_
#define SPARSE_MATRIX_HPP_
#include <vector>

class SparseMatrix { // abstract class
public:
    // Defining the pure virtual methods that _COO and _CSR have in common
    virtual int get_rows() = 0;
    virtual int get_columns() = 0;
    virtual int get_nonzeros() = 0;

    // Constructor
    SparseMatrix::SparseMatrix(const int &input_size_rows, const int &input_size_columns);

    // Copy constructor
    SparseMatrix::SparseMatrix(const SparseMatrix &other);

    // Implement access and write matrix entries by overloading the operator ()
    double &operator()(int &input_size_rows, int &input_size_columns);

    // Implement the matrix-vector product by overloading the operator *
    // SparseMatrix operator*(vettore);

    // Destructor
   /* ~SparseMatrix() {
        delete[] matrix;
    }*/

};
#endif
