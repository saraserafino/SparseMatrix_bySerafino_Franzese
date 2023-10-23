#include "SparseMatrixCOO.hpp"
#include <vector>
#include <iostream>
#include <algorithm> // for using max_element

SparseMatrixCOO::SparseMatrixCOO(std::vector<double>& values, std::vector<unsigned int>& rows, std::vector<unsigned int>& columns)
: SparseMatrix(values,columns), rows(rows) {}

// returns the number of rows of the matrix. For the way it's saved,
// the number of rows is the maximum index of row of the non-zero values
unsigned int SparseMatrixCOO::get_num_rows() const { 
  if (values.empty()) {
    return 0; // If there are no values, there is no row
  }
  return *std::max_element(rows.begin(), rows.end()) + 1;
  /* Saverio dopo che hai letto questo commento fra /* cancellalo che era solo per spiegarti
  nel caso non ricordassi che lo abbiamo visto a lezione
  Praticamente invece che fare
  unsigned int max = rows[0];
  for(auto row_idx : rows)
    if(row_idx > max)
      max = row_idx;
  return max + 1;
  basta scrivere la riga return *std::max_element(rows.begin(), rows.end()) + 1     dove
  il * serve perché così punta a quel valore (MA non è un puntatore). (row.begin, row.end) è l'intervallo
  */
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
