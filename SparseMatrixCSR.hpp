#ifndef SPARSE_MATRIX_CSR_HPP_
#define SPARSE_MATRIX_CSR_HPP_

#include "SparseMatrix.hpp"

class SparseMatrixCSR : public SparseMatrix {
public:
   SparseMatrixCSR(std::vector<double>& values, std::vector<unsigned int>& row_idx, std::vector<unsigned int>& columns);
   // Overriding the following pure virtual methods
   unsigned int get_num_rows() const override;
   double& operator()(unsigned int input_row_idx, unsigned int input_col_idx) override;
   double operator()(unsigned int input_row_idx, unsigned int input_col_idx) const override;
   std::vector<double> operator* (const std::vector<double>& vect) const override;
   void print_matrix() const override;
   SparseMatrix* convert() override;
   void print_dense_matrix() const override;

private:
// the vector row_idx_CSR of int contains the cumulative number of nonzero entries up to the i-th row excluded
std::vector<unsigned int> row_idx;
};

#endif
