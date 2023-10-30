#include "SparseMatrixCSR.hpp"
#include "SparseMatrixCOO.hpp" // we need it for the convert method
#include <iostream>

// Constructor
SparseMatrixCSR::SparseMatrixCSR(std::vector<double>& values, std::vector<unsigned int>& row_idx, std::vector<unsigned int>& columns)
: SparseMatrix(values,columns), row_idx(row_idx) {}

// Returns the number of rows of the matrix. For the way it's saved,
// the number of rows is the size of the vector row_idx - 1
unsigned int SparseMatrixCSR::get_num_rows() const {
  return values.empty() ? 0 : (row_idx.size() - 1);
}

double& SparseMatrixCSR::operator()(unsigned int input_row_idx, unsigned int input_col_idx) {
  if(input_row_idx >= this->get_num_rows() || input_col_idx >= this->get_num_columns()) {
    throw std::out_of_range ("Indexes out of range");
  }
  
  unsigned int row_start = row_idx[input_row_idx];
  unsigned int row_end = row_idx[input_row_idx + 1];

  // Check if these row and column have already a value
  for (unsigned int i = row_start; i < row_end; i++)
    if (columns[i] == input_col_idx)
      return values[i];

  // otherwise it adds it and returns the new value.
  // Compute the right position in which to insert it
  unsigned int position = row_start;
  while (position < row_end && columns[position] < input_col_idx) {
    position++;
  }

  columns.insert(columns.begin() + position, input_col_idx);
  values.insert(values.begin() + position, 0.0);

  // Update row_idx for next rows
  for (unsigned int i = input_row_idx + 1; i < row_idx.size(); i++)
    row_idx[i]++;

  return values[position];
}

// Same as above but since now it's const, it doesn't return the reference but the value
double SparseMatrixCSR::operator()(unsigned int input_row_idx, unsigned int input_col_idx) const {
  if(input_row_idx >= this->get_num_rows() || input_col_idx >= this->get_num_columns()) {
    throw std::out_of_range ("Indexes out of range");
  }
  
  unsigned int row_start = row_idx[input_row_idx];
  unsigned int row_end = row_idx[input_row_idx + 1];

  for (unsigned int i = row_start; i < row_end; i++)
    if (columns[i] == input_col_idx)
      return values[i];
  
  return 0.0;
}


std::vector<double> SparseMatrixCSR::operator* (const std::vector<double>& vect) const {
  if (this->get_num_columns() != vect.size()) {
    throw std::invalid_argument("Matrix and vector dimensions do not match");
  }

  int num_rows = this->get_num_rows();
  std::vector<double> result(num_rows, 0.0);

  for (int i = 0; i < num_rows; ++i) {
    double sum = 0.0;
    for (int j = row_idx[i]; j < row_idx[i+1]; ++j) {
      sum += values[j] * vect[columns[j]];
    }
    result[i] = sum;
  }

  return result;
}

void SparseMatrixCSR::print_matrix() const {
  std::cout << "The matrix written in CSR is: " << std::endl;
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

SparseMatrix* SparseMatrixCSR::convert() {
  std::vector<unsigned int> rows;
  rows.resize(values.size(), 0);
  int j = 0;
  for (int i = 0; i < values.size(); ++i) {
    while (j < row_idx[i + 1]) { // while new nnz values are present
      // Allocate the row indeces
      rows[j] = i;
      j++;
    }
  }

  return new SparseMatrixCOO (values, rows, columns);
}

void SparseMatrixCSR::print_dense_matrix() const {
  std::cout << "The matrix printed in a dense way is:" << std::endl;
  int j = 0; // index of the current vector columns considered
  int nnz = 0; // index of the current vector of nnz values
  int num_columns = this->get_num_columns();
  for (int i = 0; i < row_idx.size() - 1; ++i) {
    int col_num = 0; // number of column
    while (nnz < row_idx[i + 1]) { // while there are new non-zero values
      if(columns[j] == col_num) { // if the values of the column match
        std::cout << values[j] << "  "; // print the value
        j++;
        nnz++;
      }
      else { std::cout << "0  "; } // otherwise print 0
      col_num++; // go to next column
    }
    // even if there aren't new nnz values, the row may not be finished yet
    while(col_num < num_columns) {
      std::cout << "0  "; // print 0 until the row ends
      col_num++;
    }
    std::cout << "\n"; // break line between rows
  }
}