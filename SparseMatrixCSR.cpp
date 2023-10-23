#include "SparseMatrixCSR.hpp"
#include <vector>

SparseMatrixCSR::SparseMatrixCSR(std::vector<double>& values, std::vector<unsigned int>& rows, std::vector<unsigned int>& columns)
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


        row_idx.resize(size_rows + 1, 0); // initialize row_idx with 0
        current_nnz = 0;

    void setElement(int index_row, int index_col, double value) {
        if (index_row < 0 || index_row >= size_rows || index_col < 0 || index_col >= size_columns)
        {
            throw std::out_of_range("Index out of bounds.");
        }
        if (current_nnz >= nnz) {
            throw std::overflow_error("Too many non-zeros.");
        }
        values[current_nnz] = value;
        cols[current_nnz] = index_col;
        current_nnz++; 
        row_idx[index_row + 1]++;
    }

    void printmatrix() override {
        std::cout << "values = [";
        for (int i = 0; i < nnz - 1; ++i) {
            std::cout << values[i] << ", ";
        }
        std::cout << values[nnz - 1] << "]" << std::endl;
        std::cout << "columns = [";
        for (int i = 0; i < nnz - 1; ++i) {
            std::cout << cols[i] << ", ";
        }
        std::cout << cols[nnz - 1] << "]" << std::endl;
        // Calculate the cumulative sum in row_idx
        for (int i = 1; i <= index_row; ++i) {
            row_idx[i] += row.idx[i - 1];
        }
        std::cout << "row_idx = [";
        for (int i = 0; i <= index_row - 1; ++i) {
            std::cout << row_idx[i] << ", ";
        }
        std::cout << row_idx[index_row] << "]" << std::endl;
    }
