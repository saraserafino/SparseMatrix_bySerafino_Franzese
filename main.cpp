#include "SparseMatrixCOO.hpp"
#include "SparseMatrixCSR.hpp"
#include <vector>
#include <iostream>

int main(){
  std::vector<double> values = {3.1, 4, 5, 7.4, 2, 6};
  std::vector<unsigned int> rows = {0, 0, 1, 1, 3, 3};
  std::vector<unsigned int> columns = {2, 4, 2, 4, 1, 3}; // COO
  SparseMatrixCOO m(values, rows, columns);
  std::cout << "The matrix m has " << m.get_num_rows() << " rows, " << m.get_num_columns()
  << " columns and " << m.get_num_nnz() << " non-zero values." << std::endl;
  //std::cout << "m(2,4) = " << m(2,4) << std::endl;
  //m(2,4) = 6.9; // non-const version
  //std::cout << "After writing m(2,4) = 6.9, it's true that m(2,4) = " << m(2,4) << std::endl;
  m.print_matrix();
  m.convert(); // converts the matrix from COO to CSR
  m.print_dense_matrix();
  // Be aware when defining row_idx for CSR: the first element must be 0 by convention
  std::vector<unsigned int> row_idx = {0, 2, 4, 4, 6}; // CSR
  SparseMatrixCSR m2(values, row_idx, columns);
  std::cout << "The matrix m2 has " << m2.get_num_rows() << " rows, " << m2.get_num_columns()
  << " columns and " << m2.get_num_nnz() << " non-zero values." << std::endl;
  //std::cout << "m2(3,2) = " << m2(3,2) << std::endl;
  //m2(3,2) = 20;
  //m2(1,1) = 16;
  //std::cout << "After writing m2(3,2) = 20, it's true that m2(3,2) = " << m2(3,2) << std::endl;
  m2.print_matrix();
  m2.convert(); // converts the matrix from CSR to COO
  m2.print_dense_matrix();
  return 0;
}

