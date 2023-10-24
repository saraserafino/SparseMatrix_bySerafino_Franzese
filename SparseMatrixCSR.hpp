#ifndef SPARSE_MATRIX_CSR_HPP_
#define SPARSE_MATRIX_CSR_HPP_

#include "SparseMatrix.hpp"
#include <vector>

class SparseMatrixCSR : public SparseMatrix {
public:
   SparseMatrixCSR(std::vector<double>& values, std::vector<unsigned int>& row_idx, std::vector<unsigned int>& columns);
   // Overriding the following pure virtual methods
   unsigned int get_num_rows() const override;
   double& operator()(unsigned int input_row_idx, unsigned int input_col_idx) override;
   double operator()(unsigned int input_row_idx, unsigned int input_col_idx) const override;
   void print_matrix() override;
   void convert() override;
   //void print_cute_matrix() override;

private:
// the vector row_idx_CSR of int contains the cumulative number of nonzero entries up to the i-th row excluded
std::vector<unsigned int> row_idx;
};

#endif
