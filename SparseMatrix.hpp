#ifndef SPARSE_MATRIX_HPP_
#define SPARSE_MATRIX_HPP_
#include <vector>

class SparseMatrix { // abstract class
public:
    // Constructor
    SparseMatrix(std::vector<double>& values, std::vector<unsigned int>& columns);

    // If some common methods of COO and CSR don't act the same, they're defined as virtual
    virtual unsigned int get_num_rows() const = 0;
    virtual double& operator()(unsigned int row_idx, unsigned int col_idx) = 0;
    virtual double operator()(unsigned int row_idx, unsigned int col_idx) const = 0;
    // else they're not and we define them only in SparseMatrix
    unsigned int get_num_columns() const;
    unsigned int get_num_nnz() const;

    // Copy constructor
  //  SparseMatrix(const SparseMatrix &other);

    // Implement the matrix-vector product by overloading the operator *
    // SparseMatrix operator*(vettore);

//se mai definissimo un puntatore bisogna fare il virtual destructor!!
    //void printmatrix();

protected:
// the vector values contains all the nonzero values
std::vector<double> values;
// the vector columns contains their corresponding columns indices
std::vector<unsigned int> columns;
};
#endif
