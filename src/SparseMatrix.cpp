#include "SparseMatrix.hpp"

class SparseMatrix {
public:
    SparseMatrix(const int size_rows, const int size_columns, std::vector<double> &numbers)
    : size_rows(size_rows), size_columns(size_columns),  {

    }
    // Implement access and write matrix entries by overloading the operator ()
    SparseMatrix operator()(matrice) {
        
    }
    // Implement the matrix-vector product by overloading the operator *
    SparseMatrix operator*(vettore) {
        SparseMatrix result;
        result.size_rows = 1;
        result.size_columns = size_vettore;
        for (unsigned int i = 0; i < size_rows; ++i) {
            for (unsigned int j = 0; j < size_columns; ++j) {
                if (A[i,j] != 0) {
                    result[i] += A[i,j]*vettore[j];
                }
            }
        }
        return result;
    }
    // Poi scrivendo SparseMatrix matrice{}; SparseMatrix vettore{}; farai
    // SparseMatrix prodotto=matrice*vettore;
double size_rows;
double size_columns;
}; //quando lo chiami fai SparseMatrix sparsematrix{4,4} e crei una matrice 4x4
