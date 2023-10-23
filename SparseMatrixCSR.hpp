#ifndef SPARSE_MATRIX_CSR_HPP_
#define SPARSE_MATRIX_CSR_HPP_
#include "SparseMatrix.hpp"
#include <vector>

class SpareMatrixCSR : public SparseMatrix {
public:
// per ognuno dei punti richiesti (get number of rows, columns, read an entry etc) dobbiamo fare una funzione come
    /* int get_rows() override {

    }
    */
   SparseMatrixCSR(const int &input_size_rows, const int &input_size_columns, int nnz);

    void setElement(int index_row, int index_col, double value);
    // void printmatrix(); // essendo già in SparseMatrix non penso serva definirlo qua
private:
// the array rows_idx of int contains the cumulative number of nonzero entries up to the
// i-th row excluded. Its length is m+1 with m number of rows of A
std::vector<unsigned int> rows_idx;
};

#endif
