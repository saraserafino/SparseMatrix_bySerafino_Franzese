#include "SparseMatrixCSR.hpp"
#include <vector>

// the array values contains all the nonzero values
// we'll call the standard length nnz (number of non-zeros)
std::vector<double> values =
// the array columns of int contains their corresponding column indices
// so its length is the same as that of values (nnz)
std::vector<int> columns =
// the array rows_idx of int contains the cumulative number of nonzero entries up to the
// i-th row excluded. Its length is m+1 with m number of rows of A
std::vector<int> rows_idx = 
row_idx[0] = 0 // convention. In this way row_idx[i+1] - row_idx[i] represents the
// number of nonzero elements in the i-th row
