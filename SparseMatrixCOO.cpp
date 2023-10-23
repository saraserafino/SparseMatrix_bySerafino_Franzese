#include "SparseMatrixCOO.hpp"
#include <vector>
#include <iostream>

SparseMatrixCOO::SparseMatrixCOO(std::vector<double>& values, std::vector<unsigned int>& rows, std::vector<unsigned int>& columns):
  SparseMatrix(values,columns),rows(rows){}
    
    unsigned int SparseMatrixCOO::get_num_rows() const { 
          if (values.empty()) {
        return 0; // Nessuna colonna se non ci sono valori
    }  
    unsigned int max=rows[0];
    for(auto row_idx : rows)
        if(row_idx > max)
        max = row_idx;
    return max+1;
    }

 double& SparseMatrixCOO::operator()(int row_idx, int col_idx) {
 if(row_idx >= this->get_num_rows() || col_idx >= this->get_num_columns()){
    throw std::out_of_range ("Indexes out of range");
  }

  for(int i = 0; i < values.size(); i++)
    if(rows[i] == row_idx && columns[i] == col_idx)
      return values[i]; //ritorna il valore se gli indici sono presenti nei vettori rows e columns

  rows.push_back(row_idx); //altrimenti aggiungilo e ritorna il nuovo valore
  columns.push_back(col_idx);
  values.push_back(0.0); // valore di default zero, poi verrà modificato
  return values.back();
}

double SparseMatrixCOO::operator()(int row_idx, int col_idx) const { // qua è marcato const quindi non occorre ritornare la reference ma 
  if(row_idx >= this->get_num_rows() || col_idx >= this->get_num_columns()){ // basta il valore
    throw std::out_of_range ("Indexes out of range");
  }

  for(int i = 0; i < values.size(); i++)
    if(rows[i] == row_idx && columns[i] == col_idx)
      return values[i];

  return 0.0;

}
