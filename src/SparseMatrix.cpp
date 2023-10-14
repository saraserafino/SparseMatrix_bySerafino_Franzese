#include "SparseMatrix.hpp"

// The following class is an abstract class because there's at least one virtual method defined as pure virtual.
// Pure virtual functions act as placeholders for functionality that must be provided by derived classes.
// Here the derived classes are SparseMatrixCOO and SparseMatrixCSR
// They enforce a specific method signature that derived classes must adhere to.
class SparseMatrix { // abstract class
public:
    // Defining the pure virtual methods that _COO and _CSR have in common
    virtual int get_rows() = 0;
    virtual int get_columns() = 0;
    virtual int get_nonzeros() = 0;

// le seguenti cose non sono ancora modificate seguendo abstract class
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
int size_rows;
int size_columns;
private:
// the length of the following arrays is nnz (number of non-zeros)
// the array values contains all the nonzero values
std::vector<double> values;
// the array rows of int contains their corresponding row indices
std::vector<int> rows;
}; //quando lo chiami fai SparseMatrix sparsematrix{4,4} e crei una matrice 4x4