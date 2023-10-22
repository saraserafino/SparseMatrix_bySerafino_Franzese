#ifndef SPARSE_MATRIX_COO_HPP_
#define SPARSE_MATRIX__COO_HPP_

#include "SparseMatrix.hpp"
#include <vector>

class SparseMatrixCOO : public SparseMatrix {
public:

    unsigned int get_num_rows() const override;
    
    SparseMatrixCOO(const int &input_size_rows, const int &input_size_columns, int nnz);
    
    // Redefining the operator () in both const and not-const version
    double &operator()(unsigned int &input_size_rows, unsigned int &input_size_columns) override;
    double operator()(unsigned int &input_size_rows, unsigned int &input_size_columns) const override;

private:
// the length of the following array is nnz (number of non-zeros)
// the array rows contains the row indices
std::vector<unsigned int> rows;
};

#endif
