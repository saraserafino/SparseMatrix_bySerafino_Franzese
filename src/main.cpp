#include "SparseMatrixCOO.hpp"
#include "SparseMatrixCSR.hpp"
#include <iostream>

int main(){
  std::cout << "The matrix M is written in COO format." << std::endl;
  std::vector<double> values = {3.1, 4, 5, 7.4, 2, 6};
  std::vector<unsigned int> rows = {0, 0, 1, 1, 3, 3};
  std::vector<unsigned int> columns = {2, 4, 2, 4, 1, 3};
  SparseMatrixCOO M(values, rows, columns);
  std::cout << "M has " << M.get_num_rows() << " rows, " << M.get_num_columns()
  << " columns and " << M.get_num_nnz() << " non-zero values." << std::endl;
  
  std::cout << "Right now M(2,3) = " << M(2,3) << std::endl;
  M(2,3) = 5.7; // non-const version
  std::cout << "Changing its value to M(2,3) = " << M(2,3) << std::endl;

  M.print_matrix();
  std::cout << "Converting the matrix..." << std::endl;
  // M.convert() returns a pointer to SparseMatrix, we convert it to a
  // pointer to SparseMatrixCSR with casting (SparseMatrixCSR*)
  // Source: https://www.geeksforgeeks.org/static_cast-in-cpp/amp/
  SparseMatrixCSR* Mconverted = (SparseMatrixCSR*) M.convert();
  Mconverted->print_matrix();
  M.print_dense_matrix();

  std::vector<double> vector_ones(M.get_num_columns(), 1);
  auto q = M * vector_ones;

  std::cout << "The multiplication of a matrix for a vector of ones"
            << " gives the sum of the rows of the matrix. "
            << "In this case:" << std::endl << "[";
  for (int i = 0; i < M.get_num_rows() - 1; ++i) {
      std::cout << q[i] << ", ";
  }
  std::cout << q.back() << "]" << std::endl;

  std::vector<double> vector_canonical(M.get_num_columns(), 0);
  vector_canonical[3] = 1;
  auto q2 = M * vector_canonical;

  std::cout << "The multiplication of a matrix for the i-th vector of the "
            << "canonical basis gives the i-th column of the matrix." << std::endl
            << "In this case with 3th vector of the canonical basis:"
            << std::endl << "[";
  for (int i = 0; i < M.get_num_rows() - 1; ++i) {
      std::cout << q2[i] << ", ";
  }
  std::cout << q2.back() << "]" << std::endl;

  std::vector<double> vector = {-1, 0, -2, 3, 1};
  auto q3 = M * vector;

  std::cout << "Multiplication of the vector [";
  for (int i = 0; i < vector.size() - 1; ++i)
    std::cout << vector[i] << ", ";
  std::cout << vector.back() << "] for the matrix M:" << std::endl;
  std::cout << "Expected value: [-2.2, -2.6, 17.1, 18]" << std::endl;
  std::cout << "Actual value: [";
  for (int i = 0; i < M.get_num_rows() - 1; ++i) {
      std::cout << q3[i] << ", ";
  }
  std::cout << q3.back() << "]" << std::endl << std::endl;


  // Be aware when defining row_idx for CSR: the first element must be 0 by convention
  std::cout << "The matrix M2 is written in CSR format." << std::endl;
  std::vector<unsigned int> row_idx = {0, 2, 4, 4, 6};
  SparseMatrixCSR M2(values, row_idx, columns);
  std::cout << "M2 has " << M2.get_num_rows() << " rows, " << M2.get_num_columns()
  << " columns and " << M2.get_num_nnz() << " non-zero values." << std::endl;

  std::cout << "Right now M2(2,3) = " << M2(2,3) << std::endl;
  M2(2,3) = 5.7; // non-const version
  std::cout << "Changing its value to M2(2,3) = " << M2(2,3) << std::endl;

  M2.print_matrix();
  std::cout << "Converting the matrix..." << std::endl;
  SparseMatrixCOO* M2converted = (SparseMatrixCOO*) M2.convert();
  M2converted->print_matrix();
  M2.print_dense_matrix();
  
  auto q4 = M2 * vector_ones;
  std::cout << "Multiplying the matrix M2 for a vector of ones "
            << "we obtain the sum of the rows of the matrix:"
            << std::endl << "[";
  for (int i = 0; i < M2.get_num_rows() - 1; ++i) {
      std::cout << q4[i] << ", ";
  }
  std::cout << q4.back() << "]" << std::endl;

  auto q5 = M2 * vector_canonical;
  std::cout << "The multiplication of a matrix for the i-th vector of the "
            << "canonical basis gives the i-th column of the matrix." << std::endl
            << "In this case with 3th vector of the canonical basis:"
            << std::endl << "[";
  for (int i = 0; i < M2.get_num_rows() - 1; ++i) {
      std::cout << q5[i] << ", ";
  }
  std::cout << q5.back() << "]" << std::endl;

  auto q6 = M2 * vector;

  std::cout << "Multiplication of the vector [";
  for (int i = 0; i < vector.size() - 1; ++i)
    std::cout << vector[i] << ", ";
  std::cout << vector.back() << "] for the matrix M2:" << std::endl;
  std::cout << "Expected value: [-2.2, -2.6, 17.1, 18]" << std::endl;
  std::cout << "Actual value: [";
  for (int i = 0; i < M2.get_num_rows() - 1; ++i) {
      std::cout << q6[i] << ", ";
  }
  std::cout << q6.back() << "]" << std::endl;
  
  // Deallocate the pointers
  delete Mconverted;
  delete M2converted;

  return 0;
}