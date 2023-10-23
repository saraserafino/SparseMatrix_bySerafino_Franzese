#ifndef SPARSE_MATRIX_CSR_HPP_
#define SPARSE_MATRIX_CSR_HPP_

#include "SparseMatrix.hpp"
#include <vector>

class SpareMatrixCSR : public SparseMatrix {
public:
   SparseMatrixCSR(std::vector<double>& values, std::vector<unsigned int>& rows, std::vector<unsigned int>& columns);
   unsigned int get_num_rows() const override;
   // Redefining the operator () in both const and not-const version
   double& operator()(unsigned int row_idx, unsigned int col_idx) override;
   double operator()(unsigned int row_idx, unsigned int col_idx) const override;

private:
// the array rows_idx of int contains the cumulative number of nonzero entries up to the
// i-th row excluded. Its length is m+1 with m number of rows of A
std::vector<unsigned int> rows_idx;
};

#endif
