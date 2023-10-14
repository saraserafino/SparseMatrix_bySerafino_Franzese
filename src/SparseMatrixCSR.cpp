#include "SparseMatrixCSR.hpp"
#include <vector>

class SpareMatrixCSR : public SparseMatrix {
public:
// per ognuno dei punti richiesti (get number of rows, columns, read an entry etc) dobbiamo fare una funzione come
    int get_rows() override {

    }
private:
// the array rows_idx of int contains the cumulative number of nonzero entries up to the
// i-th row excluded. Its length is m+1 with m number of rows of A
std::vector<int> rows_idx;
// il seguente va nel costruttore PIANGO
row_idx[0] = 0 // convention. In this way row_idx[i+1] - row_idx[i] represents the
// number of nonzero elements in the i-th row
};