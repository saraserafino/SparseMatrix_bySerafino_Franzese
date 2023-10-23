#include "SparseMatrix.hpp"
#include <iostream>

// Constructor
SparseMatrix::SparseMatrix(std::vector<double>& values, std::vector<unsigned int>& columns): values{values}, columns{columns}{}


//ritorna il numero di elementi non nulli
unsigned int SparseMatrix::get_num_nnz() const {
    return values.size();
    }

//ritorna il numero di colonne della matrice (per come è salvata, il numero di colonne è il massimo indice di colonna dei
//numeri non nulli)
unsigned int SparseMatrix::get_num_columns() const {
    if (values.empty()) {
        return 0; // Nessuna colonna se non ci sono valori
    }
    unsigned int max=columns[0];
    for (unsigned int i=0; i<columns[values.size()]; i++)
    if(max<columns[i]){
        max=columns[i];
    }
    return max;
}

/* Copy costructor
SparseMatrix::SparseMatrix(const SparseMatrix &other) {
    matrix = new double[other.lunghezza];
    size_columns = other.size_columns;
    size_rows = other.size_rows;
    lunghezza = other.lunghezza;
    // il seguente penso dia problemi per il fatto che ci sono gli 0 non dichiarati, casomai da dire che se non c'è è 0
    for (unsigned int i = 0; i < lunghezza; i++){
        matrix[i]= other.matrix[i];
    }
    }

void printmatrix() {
    // qui vogliamo stamparla (in modo univoco) dicendo che se non ci sono valori assegnati mette 0
}
*/
