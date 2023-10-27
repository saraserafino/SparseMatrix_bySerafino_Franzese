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
  
  std::cout << "m(1,0) = " << m(1,0) << std::endl;
  std::cout << "m(2,3) = " << m(2,3) << std::endl;
  m(1,0) = 6.9; // non-const version
  m(2,3) = 5.7;
  std::cout << "Changing their value to" << std::endl;
  std::cout << "m(1,0) = " << m(1,0) << std::endl;
  std::cout << "m(2,3) = " << m(2,3) << std::endl;

  m.print_matrix();
  m.convert(); // convert the matrix from COO to CSR
  m.print_dense_matrix();

  // Be aware when defining row_idx for CSR: the first element must be 0 by convention
  std::vector<unsigned int> row_idx = {0, 2, 4, 4, 6}; // CSR
  SparseMatrixCSR m2(values, row_idx, columns);
  std::cout << "The matrix m2 has " << m2.get_num_rows() << " rows, " << m2.get_num_columns()
  << " columns and " << m2.get_num_nnz() << " non-zero values." << std::endl;

  std::cout << "m2(1,0) = " << m2(1,0) << std::endl;
  std::cout << "m2(2,3) = " << m2(2,3) << std::endl;
  m2(1,0) = 6.9; // non-const version
  m2(2,3) = 5.7;
  std::cout << "Changing their value to" << std::endl;
  std::cout << "m2(1,0) = " << m2(1,0) << std::endl;
  std::cout << "m2(2,3) = " << m2(2,3) << std::endl;

  m2.print_matrix();
  m2.convert(); // convert the matrix from CSR to COO
  m2.print_dense_matrix();
/*
  std::vector<double> vector1 = {1, 2, 0, 3};
  std::vector<double> result = m2 * vector1;
  // Print result
  std::cout << "Product matrix-vector = [";
  for (int i = 0; i < result.size() - 1; ++i)
    std::cout << result[i] << ", ";
  std::cout << result.back() << "]" << std::endl;
  */
  return 0;
}

