#ifndef SPARSE_MATRIX_HPP_
#define SPARSE_MATRIX_HPP_
#include <vector>

class SparseMatrix { // abstract class
public:
    // Constructor
    SparseMatrix(std::vector<double>& values, std::vector<unsigned int>& columns);
    // If some common methods of COO and CSR don't act the same, they're defined as virtual
    virtual unsigned int get_num_rows() const = 0;
    // else they're not and we define them only in SparseMatrix
    unsigned int get_num_columns() const;
    unsigned int get_num_nnz() const;
    virtual double& operator()(int row_idx, int col_idx) = 0;
    virtual double operator()(int row_idx, int col_idx) const = 0;
/*
    // Redefining the operator () in both const and not-const version
    // in order to implement respectively access and write matrix entries
    virtual double operator()(unsigned int &input_size_rows, unsigned int &input_size_columns) const = 0;
    virtual double &operator()(unsigned int &input_size_rows, unsigned int &input_size_columns) = 0;
*/    

    // Copy constructor
  //  SparseMatrix(const SparseMatrix &other);


    // Implement the matrix-vector product by overloading the operator *
    // SparseMatrix operator*(vettore);

    // Virtual destructor
 //   virtual ~SparseMatrix() { delete[] values; };
//    void printmatrix();

protected:
// the array values contains all the nonzero values
std::vector<double> values;
// the array columns contains their corresponding columns indices
std::vector<unsigned int> columns;
};
#endif
