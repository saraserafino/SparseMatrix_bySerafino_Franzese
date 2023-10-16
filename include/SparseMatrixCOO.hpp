#ifndef SPARSE_MATRIX_COO_HPP_
#define SPARSE_MATRIX__COO_HPP_
// #include <vector>

class SpareMatrixCOO : public SparseMatrix {
public:
// per ognuno dei punti richiesti (get number of rows, columns, read an entry etc) dobbiamo fare una funzione come
    /*
    int get_rows() override {

    }
    */
   SparseMatrixCOO(const int &input_size_rows, const int &input_size_columns, int nnz);
   void setElement(int index_row, int index_col, double value);
    // void printmatrix(); // essendo già in SparseMatrix non penso serva definirlo qua

private:
// the length of the following array is nnz (number of non-zeros)
// the array rows of int contains their corresponding rows indices
std::vector<int> rows;
int current_nnz;
};

#endif
