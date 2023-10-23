#include "SparseMatrixCOO.hpp"
#include <vector>
#include <iostream>

SparseMatrixCOO::SparseMatrixCOO(std::vector<double>& values, std::vector<unsigned int>& rows, std::vector<unsigned int>& columns)
: SparseMatrix(values,columns), rows(rows) {}
    
unsigned int SparseMatrixCOO::get_num_rows() const { 
  if (values.empty()) {
    return 0; // If there are no values, there is no row
  }
  unsigned int max = rows[0];
  for(auto row_idx : rows)
    if(row_idx > max)
      max = row_idx;
  return max + 1;
}

double& SparseMatrixCOO::operator()(unsigned int row_idx, unsigned int col_idx) {
  if(row_idx >= this->get_num_rows() || col_idx >= this->get_num_columns()) {
    throw std::out_of_range ("Indexes out of range");
  }

  for(int i = 0; i < values.size(); ++i)
    if(rows[i] == row_idx && columns[i] == col_idx) // if the indeces are present in the vectors rows and columns
      return values[i]; // it returns the value
  // otherwise it adds it and returns the new value
  rows.push_back(row_idx);
  columns.push_back(col_idx);
  values.push_back(0.0); // default value of 0 that will be changed later
  return values.back();
}

// Same as above but since now it's const, it doesn't return the reference but the value
double SparseMatrixCOO::operator()(unsigned int row_idx, unsigned int col_idx) const {
  if(row_idx >= this->get_num_rows() || col_idx >= this->get_num_columns()) {
    throw std::out_of_range ("Indexes out of range");
  }

  for(int i = 0; i < values.size(); ++i)
    if(rows[i] == row_idx && columns[i] == col_idx)
      return values[i];

  return 0.0;
}
