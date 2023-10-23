#ifndef SPARSE_MATRIX_COO_HPP_
#define SPARSE_MATRIX_COO_HPP_

#include "SparseMatrix.hpp"
#include <vector>

class SparseMatrixCOO : public SparseMatrix {
public:
    SparseMatrixCOO(std::vector<double>& values, std::vector<unsigned int>& rows, std::vector<unsigned int>& columns);
    unsigned int get_num_rows() const override;
    // Redefining the operator () in both const and not-const version
    double& operator()(unsigned int row_idx, unsigned int col_idx) override; // overload secondo il suo metodo di salvare i valori
    double operator()(unsigned int row_idx, unsigned int col_idx) const override;

private:
// the array rows contains the row indices
std::vector<unsigned int> rows;
};

#endif
