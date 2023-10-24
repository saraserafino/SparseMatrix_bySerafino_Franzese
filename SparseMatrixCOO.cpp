#include "SparseMatrixCOO.hpp"
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
  Già che cancellerai questo commento ne approfitto per dirti qui che ho cambiato tutti i row_idx e col_idx
  in input_row_idx e input_col_idx per rendere un po' più comprensibile visto che anche in CSR si chiama row_idx
  e poi ricordo che anche il prof aveva scritto input_qualcosa. Insomma questo input_ è quello che scrivi da tastiera quando inserisci
  */
}

double& SparseMatrixCOO::operator()(unsigned int input_row_idx, unsigned int input_col_idx) {
  if(input_row_idx >= this->get_num_rows() || input_col_idx >= this->get_num_columns()) {
    throw std::out_of_range ("Indexes out of range");
  }

  for(int i = 0; i < values.size(); ++i)
    // if the indexes are present in the vectors rows and columns
    if(rows[i] == input_row_idx && columns[i] == input_col_idx)
      return values[i]; // it returns the value
  // otherwise it adds it and returns the new value
  rows.push_back(input_row_idx);
  columns.push_back(input_col_idx);
  values.push_back(0.0); // default value of 0 that will be changed later
  return values.back();
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

void SparseMatrixCOO::print_matrix() {
  std::cout << "values = [";
  for (int i = 0; i < values.size() - 1; ++i)
    std::cout << values[i] << ", ";
  std::cout << values[values.size() - 1] << "]" << std::endl;
  std::cout << "rows = [";
  for (int i = 0; i < rows.size() - 1; ++i)
    std::cout << rows[i] << ", ";
  std::cout << rows[rows.size() - 1] << "]" << std::endl;
  std::cout << "columns = [";
  for (int i = 0; i < columns.size() - 1; ++i)
    std::cout << columns[i] << ", ";
  std::cout << columns[columns.size() - 1] << "]" << std::endl;
}