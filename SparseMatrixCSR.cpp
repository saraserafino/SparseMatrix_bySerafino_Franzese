#include "SparseMatrixCSR.hpp"
#include "SparseMatrixCOO.hpp" // we need it for the convert method
#include <iostream>

SparseMatrixCSR::SparseMatrixCSR(std::vector<double>& values, std::vector<unsigned int>& row_idx, std::vector<unsigned int>& columns)
: SparseMatrix(values,columns), row_idx(row_idx) {}

unsigned int SparseMatrixCSR::get_num_rows() const {
  return values.empty() ? 0 : (row_idx.size() - 1);
}

double& SparseMatrixCSR::operator()(unsigned int input_row_idx, unsigned int input_col_idx) {
  if(input_row_idx >= this->get_num_rows() || input_col_idx >= this->get_num_columns()) {
    throw std::out_of_range ("Indexes out of range");
  }

  for(int i = 0; i < values.size(); ++i)
  // The following if checks if there is at least a non-zero value in that row
  // and if the index of the column is already present
  // Example: given row_idx{0,2,4} and A(2,2); it checks if row_idx[2] - row_idx[1] > 0
  // which is true because 4 - 2 = 2 > 0

  // in realtà dovrei mettere un check che non siano già stati inseriti tutti i nnz disponibili??
  // oltretutto non funziona come vorrei perché se da tastiera chiedo A(2,2) mi dà 3.1 anziché 0 (matrice del prof)
  // e quando sovrascrivo appunto cambia il suo valore, quindi devo aver sbagliato qualcosa
  // Inoltre è da sistemare perché scrivendo A(2,2) scrive da riga 1 colonna 2, siccome in COO abbiamo fatto 2,2, anche qui vorrei 2
    if((row_idx[input_row_idx] - row_idx[input_row_idx - 1]) > 0 && columns[i] == input_col_idx)
      return values[i]; // it returns the value
  // otherwise it adds it and returns the new value
  for(int i = input_row_idx; i < row_idx.size(); ++i) // starting from the row in which a new nnz is inserted
    row_idx[i]++; // increment the value of row_idx[i]
  columns.push_back(input_col_idx);
  values.push_back(0.0); // default value of 0 that will be changed later
  return values.back();
}

// Same as above but since now it's const, it doesn't return the reference but the value
double SparseMatrixCSR::operator()(unsigned int input_row_idx, unsigned int input_col_idx) const {
  if(input_row_idx >= this->get_num_rows() || input_col_idx >= this->get_num_columns()) {
    throw std::out_of_range ("Indexes out of range");
  }

  for(int i = 0; i < values.size(); ++i)
    if((row_idx[input_row_idx] - row_idx[input_row_idx - 1]) > 0 && columns[i] == input_col_idx)
      return values[i];

  return 0.0;
}

void SparseMatrixCSR::print_matrix() {
  std::cout << "values = [";
  for (int i = 0; i < values.size() - 1; ++i)
    std::cout << values[i] << ", ";
  std::cout << values.back() << "]" << std::endl;
  std::cout << "columns = [";
  for (int i = 0; i < columns.size() - 1; ++i)
    std::cout << columns[i] << ", ";
  std::cout << columns.back() << "]" << std::endl;
  std::cout << "row_idx = [";
  for (int i = 0; i < row_idx.size() - 1; ++i)
    std::cout << row_idx[i] << ", ";
  std::cout << row_idx.back() << "]" << std::endl;
}

void SparseMatrixCSR::convert() {
  std::vector<unsigned int> rows;
  rows.resize(values.size(), 0);
  int j = 0;
  for (int i = 0; i < values.size(); ++i) {
    while (j < row_idx[i + 1]) { // while new non-zero values are present
      // Allocate the row indexes
      rows[j] = i;
      j++;
    }
  }
  SparseMatrixCOO matrix_converted(values, rows, columns);
  std::cout << "The matrix converted in COO is:" << std::endl;
  matrix_converted.print_matrix();
}

void SparseMatrixCSR::print_cute_matrix() {
  for(int i = 0; i < this->get_num_rows(); ++i) {
    for(int j = 0; j < this->get_num_columns(); ++j) {
      for(int k = 0; k < this->get_num_nnz(); ++k) {
        if(rows[k] == i && columns[k] == j)
          std::cout << values[k] << " ";
        else
          std::cout << "0 ";
        }
    }
    std::cout << std::endl;
  }
}