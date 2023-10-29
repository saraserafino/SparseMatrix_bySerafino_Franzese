#ifndef SPARSE_MATRIX_HPP_
#define SPARSE_MATRIX_HPP_
#include <vector>

class SparseMatrix { // abstract class
public:
    // Constructor
    SparseMatrix(std::vector<double>& values, std::vector<unsigned int>& columns);

    // If some common methods of COO and CSR don't act the same, they're defined as virtual
    virtual unsigned int get_num_rows() const = 0;
    virtual double& operator()(unsigned int input_row_idx, unsigned int input_col_idx) = 0;
    virtual double operator()(unsigned int input_row_idx, unsigned int input_col_idx) const = 0;
    virtual std::vector<double> operator* (const std::vector<double>& vect) const = 0;
    virtual void print_matrix() const = 0;
    virtual void print_dense_matrix() const = 0;
    // We define the following in this way because we want to return a matrix in the other format
    virtual SparseMatrix* convert() = 0;
    // else they're not and we define them only in SparseMatrix
    unsigned int get_num_columns() const;
    unsigned int get_num_nnz() const;

protected:
// the vector values contains all the nonzero values
std::vector<double> values;
// the vector columns contains their corresponding columns indices
std::vector<unsigned int> columns;
};
#endif
