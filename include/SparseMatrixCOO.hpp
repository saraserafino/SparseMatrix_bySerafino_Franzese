#ifndef SPARSE_MATRIX_COO_HPP_
#define SPARSE_MATRIX_COO_HPP_

#include "SparseMatrix.hpp"

class SparseMatrixCOO : public SparseMatrix {
public:
    // Constructor
    SparseMatrixCOO(std::vector<double>& values, std::vector<unsigned int>& rows, std::vector<unsigned int>& columns);
    
    // Overriding the following pure virtual methods
    unsigned int get_num_rows() const override;
    double& operator()(unsigned int input_row_idx, unsigned int input_col_idx) override;
    double operator()(unsigned int input_row_idx, unsigned int input_col_idx) const override;
    std::vector<double> operator* (const std::vector<double>& vect) const override;
    void print_matrix() const override;
    SparseMatrix* convert() override;
    void print_dense_matrix() const override;

private:
// the vector rows contains the row indices
std::vector<unsigned int> rows;
};

#endif
