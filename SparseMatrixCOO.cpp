#include "SparseMatrixCOO.hpp"
#include "SparseMatrixCSR.hpp" // we need it for the convert method
#include <iostream>
#include <algorithm> // for using max_element

SparseMatrixCOO::SparseMatrixCOO(std::vector<double>& values, std::vector<unsigned int>& rows, std::vector<unsigned int>& columns)
: SparseMatrix(values,columns), rows(rows) {}

// returns the number of rows of the matrix. For the way it's saved,
// the number of rows is the maximum index of row of the non-zero values
unsigned int SparseMatrixCOO::get_num_rows() const {
  return values.empty() ? 0 : (*std::max_element(rows.begin(), rows.end()) + 1);
}
  /* Saverio dopo che hai letto questo commento cancellalo che era solo per spiegarti 
  Praticamente qua sopra nel get_num_rows partivamo da
  
  if (values.empty()) {
    return 0; // If there are no values, there is no row
  }
  unsigned int max = rows[0];
  for(auto row_idx : rows)
    if(row_idx > max)
      max = row_idx;
  return max + 1;

  Invece che fare da unsigned in poi, basta sostituire con
  return *std::max_element(rows.begin(), rows.end()) + 1     dove
  il * serve perché così punta a quel valore (MA non è un puntatore). (row.begin, row.end) è l'intervallo.
  Ok quindi ora avremmo

  if (values.empty()) {
    return 0; // If there are no values, there is no row
  }
  return *std::max_element(rows.begin(), rows.end()) + 1;

  Che come visto nella lezione di martedì si può ulteriormente ridurre scrivendo quello che
  effettivamente ho scritto. Praticamente se è vera la cosa prima di ? ti ritorna il primo
  valore (qui 0), se no ti ritorna il secondo (qui *std...)

  Già che cancellerai questo commento ne approfitto per dirti qui che ho cambiato tutti i row_idx e col_idx
  in input_row_idx e input_col_idx per rendere un po' più comprensibile visto che anche in CSR si chiama row_idx
  e poi ricordo che anche il prof aveva scritto input_qualcosa.
  Insomma questo input_ è quello che scrivi da tastiera quando inserisci
  */

double& SparseMatrixCOO::operator()(unsigned int input_row_idx, unsigned int input_col_idx) {
  if(input_row_idx >= this->get_num_rows() || input_col_idx >= this->get_num_columns()) {
    throw std::out_of_range ("Indexes out of range");
  }

  for(int i = 0; i < values.size(); ++i)
    // if the indexes are present in the vectors rows and columns
    if(rows[i] == input_row_idx && columns[i] == input_col_idx)
      return values[i]; // it returns the value
  // otherwise it adds it and returns the new value, keeping an
  // increasing order in rows (and consequently values and columns).
  // Compute the right position in which to insert
  int position = 0;
  for (int i = 0; i < rows.size(); ++i) {
    if(rows[i] == input_row_idx + 1) {
      position = i;
      break;
    }
  }
  // commentino su quanto fatto sotto, poi cancella il commento.
  // la prima roba fra parentesi è il posto in cui aggiungi (inizio+position),
  // la seconda è il valore che aggiungi
  rows.insert(rows.begin() + position, input_row_idx);
  columns.insert(columns.begin() + position, input_col_idx);
  values.insert(values.begin() + position, 0.0); // default value of 0 that will be changed later
  return values.back(); // returns a reference to the last element in values
  // aspe però vuol dire che la reference è all'ultimo inteso tail che ora che ho ordinato
  // non c'entra un cazzo. Che si fa?
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

void SparseMatrixCOO::convert() {
  std::vector<unsigned int> row_converted;
  row_converted.resize(this->get_num_rows() + 1, 0);
  // Count the number of nnz elements in each row
  for (int i = 0; i < values.size(); ++i)
    row_converted[rows[i] + 1]++;
  // Cumulative sum for obtaining row_idx
  for (int i = 2; i < row_converted.size(); ++i)
    row_converted[i] += row_converted[i - 1];
  SparseMatrixCSR matrix_converted(values, row_converted, columns);
  std::cout << "The matrix converted in CSR is:" << std::endl;
  matrix_converted.print_matrix();
}
/*
void SparseMatrixCOO::print_cute_matrix() {
  for (int i = 0; i < rows.size(); ++i) {
    for (int j = 0; j < columns.size(); ++j) {

    }
  }
    // se non c'è nessun elemento printa 0
}
*/