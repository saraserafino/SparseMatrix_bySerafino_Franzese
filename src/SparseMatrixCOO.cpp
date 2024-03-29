#include "SparseMatrixCOO.hpp"
#include "SparseMatrixCSR.hpp" // for the convert method
#include <iostream>
#include <algorithm> // for max_element
#include <stdexcept> // for out_of_range and invalid_argument

// Constructor
SparseMatrixCOO::SparseMatrixCOO(std::vector<double>& values, std::vector<unsigned int>& rows, std::vector<unsigned int>& columns)
: SparseMatrix(values,columns), rows(rows) {}

// Returns the number of rows of the matrix. For the way it's saved,
// the number of rows is the maximum index of row of the the non-zero values + 1
unsigned int SparseMatrixCOO::get_num_rows() const {
  return values.empty() ? 0 : (*std::max_element(rows.begin(), rows.end()) + 1);
}

double& SparseMatrixCOO::operator()(unsigned int input_row_idx, unsigned int input_col_idx) {
  if(input_row_idx >= this->get_num_rows() || input_col_idx >= this->get_num_columns()) {
    throw std::out_of_range ("Indexes out of range");
  } // Source: https://stackoverflow.com/questions/2709719/throwing-out-of-range-exception-in-c 

  for(int i = 0; i < values.size(); ++i)
    // Check if these row and column have already a value
    if(rows[i] == input_row_idx && columns[i] == input_col_idx)
      return values[i];

  // otherwise it adds it and returns the new value, keeping an
  // increasing order in rows (and consequently values and columns).
  // Compute the right position in which to insert
  // Source: https://www.geeksforgeeks.org/vector-insert-function-in-cpp-stl/amp/
  int position = 0;
  for (int i = 0; i < rows.size(); ++i) {
    if(rows[i] >= input_row_idx) {
      position = i;
      break;
    }
  }
  rows.insert(rows.begin() + position, input_row_idx);
  columns.insert(columns.begin() + position, input_col_idx);
  values.insert(values.begin() + position, 0.0); // default value of 0 that will be changed later
  return values[position];
}

// Same as above but since now it's const, it doesn't return the reference but the value
double SparseMatrixCOO::operator()(unsigned int input_row_idx, unsigned int input_col_idx) const {
  if(input_row_idx >= this->get_num_rows() || input_col_idx >= this->get_num_columns()) {
    throw std::out_of_range ("Indexes out of range");
  }

  for(int i = 0; i < values.size(); ++i)
    if(rows[i] == input_row_idx && columns[i] == input_col_idx)
      return values[i];

  return 0.0;
}

std::vector<double> SparseMatrixCOO::operator*(const std::vector<double>& vect) const {
  if (this->get_num_columns() != vect.size()) {
    throw std::invalid_argument("Matrix and vector dimensions do not match");
  } // Source: https://stackoverflow.com/questions/28554927/c-error-invalid-argument-was-not-declared-in-this-scope 

  int num_rows = this->get_num_rows();
  std::vector<double> result(num_rows, 0.0);
  int j = 0; // index of the current vector values considered
  for (int i = 0; i < num_rows; ++i) {
    double sum = 0.0;
    // while still in the same row
    while (j < values.size() && rows[j] == i) {
      sum += values[j] * vect[columns[j]];
      j++;
    }
    result[i] = sum;
  }

  return result;
}

void SparseMatrixCOO::print_matrix() const {
  std::cout << "The matrix written in COO is: " << std::endl;
  std::cout << "values = [";
  for (int i = 0; i < values.size() - 1; ++i)
    std::cout << values[i] << ", ";
  std::cout << values.back() << "]" << std::endl;

  std::cout << "rows = [";
  for (int i = 0; i < rows.size() - 1; ++i)
    std::cout << rows[i] << ", ";
  std::cout << rows.back() << "]" << std::endl;

  std::cout << "columns = [";
  for (int i = 0; i < columns.size() - 1; ++i)
    std::cout << columns[i] << ", ";
  std::cout << columns.back() << "]" << std::endl;
}

SparseMatrix* SparseMatrixCOO::convert() {
  std::vector<unsigned int> row_converted(this->get_num_rows() + 1, 0);
  // Count the number of nnz elements in each row
  for (int i = 0; i < values.size(); ++i)
    row_converted[rows[i] + 1]++;
  // Cumulative sum for obtaining row_idx
  for (int i = 2; i < row_converted.size(); ++i)
    row_converted[i] += row_converted[i - 1];

  return new SparseMatrixCSR (values, row_converted, columns);
}

void SparseMatrixCOO::print_dense_matrix() const {
  std::cout << "The matrix printed in a dense way is:" << std::endl;
  int j = 0; // index of the current vector columns considered
  int i = 0; // index of the current vector rows considered
  int num_columns = this->get_num_columns();
  for(int k = 0; k < this->get_num_rows(); ++k) {
    int col_num = 0; // number of column
    while(k == rows[i]) { // while still in the same row
      if(columns[j] == col_num) { // if the value matches
        std::cout << values[j] << "  "; // print the value
        j++;
        i++;
      }
      else { std::cout << "0  "; } // otherwise print 0
      col_num++; // go to next column
    }
    // even if there aren't other nnz values in a row, the row may not be finished yet
    while(col_num < num_columns) {
      std::cout << "0  "; // print 0 until the row ends
      col_num++;
    }
    std::cout << "\n"; // break line between rows
  }
}