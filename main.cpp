#include "SparseMatrixCOO.hpp"
#include "SparseMatrixCSR.hpp"
#include <vector>
#include <iostream>

int main(){
  std::vector<double> values = {1,2,3};
  std::vector<unsigned int> columns = {0,2,4};
  std::vector<unsigned int> rows = {1,0,3}; // COO
  SparseMatrixCOO m(values, rows, columns);
  std::cout << "numero di elementi non nulli: " << m.get_num_nnz();
  std::cout << "matrix m with " << m.get_num_rows() << " rows and " << m.get_num_columns() << " columns\n";
  std::cout << "m(1,0): " << m(1,0) << std::endl;
  m(2,2) = 100;
  std::cout << "Dopo m(2,2) = 100, cout di m(2,2) da: " << m(2,2) << std::endl;
  // Be aware that when defining row_idx for CSR, the first element must be 0 by convention
  std::vector<unsigned int> row_idx = {0,2,4}; // CSR
  SparseMatrixCSR m2(values, row_idx, columns);
  return 0;
}

