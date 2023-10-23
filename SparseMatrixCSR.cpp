#include "SparseMatrixCSR.hpp"
#include <vector>

SparseMatrixCSR::SparseMatrixCSR(std::vector<double>& values, std::vector<unsigned int>& rows, std::vector<unsigned int>& columns)
: SparseMatrix(values,columns), rows(rows) {}

// forse get_num_rows anche va in SparseMatrix perché comunque ci interessa prenderlo normale e poi creare quella strana di CSR
unsigned int SparseMatrixCSR::get_num_rows() const { 
  if (values.empty()) {
    return 0; // If there are no values, there is no row
  }
  unsigned int max = rows[0];
  for(auto row_idx : rows)
    if(row_idx > max)
      max = row_idx;
  return max + 1;
}

// Creo il metodo per scrivere row_idx_CSR
auto get_row_idx_CSR() {
  row_idx_CSR[0] = 0; // convention
  row_idx_CSR.resize(this->get_num_rows() + 1); // its length is 1 more than the number of rows
  
}

double& SparseMatrixCSR::operator()(unsigned int row_idx, unsigned int col_idx) {
  if(row_idx >= this->get_num_rows() || col_idx >= this->get_num_columns()) {
    throw std::out_of_range ("Indexes out of range");
  }

  for(int i = 0; i < values.size(); ++i)
    if((devo far capire la riga) == row_idx && columns[i] == col_idx) // if the indeces are present in the vectors row_idx_CSR and columns
      return values[i]; // it returns the value
  // otherwise it adds it and returns the new value
  rows.push_back(row_idx);
  columns.push_back(col_idx);
  values.push_back(0.0); // default value of 0 that will be changed later
  return values.back();
}

// Same as above but since now it's const, it doesn't return the reference but the value
double SparseMatrixCSR::operator()(unsigned int row_idx, unsigned int col_idx) const {
  if(row_idx >= this->get_num_rows() || col_idx >= this->get_num_columns()) {
    throw std::out_of_range ("Indexes out of range");
  }

  for(int i = 0; i < values.size(); ++i)
    if(rows[i] == row_idx && columns[i] == col_idx)
      return values[i];

  return 0.0;
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
