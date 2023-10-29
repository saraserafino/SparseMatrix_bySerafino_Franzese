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
  
  std::cout << "m(2,3) = " << m(2,3) << std::endl;
  m(2,3) = 5.7; // non-const version
  std::cout << "Changing its value to" << std::endl;
  std::cout << "m(2,3) = " << m(2,3) << std::endl;

  m.print_matrix();
  m.convert(); // convert the matrix from COO to CSR
  m.print_dense_matrix();

  std::vector<double> vector_ones(m.get_num_columns(),1);
  auto q = m * vector_ones;

  std::cout << "The multiplication of the matrix for a vector of ones"
            << " gives the sum of the rows of the matrix: " << std::endl;
  for (int i = 0; i < m.get_num_rows(); ++i) {
      std::cout << q[i] << " ";
  }
  std::cout << std::endl;

  std::vector<double> vector_canonical(m.get_num_columns(),0);
  vector_canonical[3] = 1;
  auto q2 = m * vector_canonical;

  std::cout << "The multiplication of the matrix for the i-th vector of the"
            << " canonical basis gives the i-th column of the matrix." << std::endl
            << "For example the 3th vector of the canonical basis"
            << " gives the 3th column of the matrix:" << std::endl;
  for (int i = 0; i < m.get_num_rows(); ++i) {
      std::cout << q2[i] << " ";
  }
  std::cout << std::endl;

  // Be aware when defining row_idx for CSR: the first element must be 0 by convention
  std::vector<unsigned int> row_idx = {0, 2, 4, 4, 6}; // CSR
  SparseMatrixCSR m2(values, row_idx, columns);
  std::cout << "The matrix m2 has " << m2.get_num_rows() << " rows, " << m2.get_num_columns()
  << " columns and " << m2.get_num_nnz() << " non-zero values." << std::endl;

  std::cout << "m2(2,3) = " << m2(2,3) << std::endl;
  m2(2,3) = 5.7; // non-const version
  std::cout << "Changing its value to" << std::endl;
  std::cout << "m2(2,3) = " << m2(2,3) << std::endl;


  m2.print_matrix();
  m2.convert(); // convert the matrix from CSR to COO
  m2.print_dense_matrix();
  
  auto q3 = m2 * vector_ones;
  std::cout << "The multiplication of the matrix for a vector of ones"
            << " gives the sum of the rows of the matrix: " << std::endl;
  for (int i = 0; i < m2.get_num_rows(); ++i) {
      std::cout << q3[i] << " ";
  }
  std::cout << std::endl;

  auto q4 = m2 * vector_canonical;
  std::cout << "The multiplication of the matrix for the i-th vector of the"
            << " canonical basis gives the i-th column of the matrix." << std::endl
            << "For example the 3th vector of the canonical basis"
            << " gives the 3th column of the matrix." << std::endl;
  for (int i = 0; i < m2.get_num_rows(); ++i) {
      std::cout << q4[i] << " ";
  }
  std::cout << std::endl;
  
  return 0;
}

