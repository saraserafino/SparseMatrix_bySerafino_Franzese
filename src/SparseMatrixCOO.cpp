#include "SparseMatrixCOO.hpp"
#include <vector>

class SpareMatrixCOO : public SparseMatrix {
public:
// per ognuno dei punti richiesti (get number of rows, columns, read an entry etc) dobbiamo fare una funzione come
    int get_rows() override {

    }
// the length of the following array is nnz (number of non-zeros)
// the array cols of int contains their corresponding column indices
std::vector<int> cols;
};