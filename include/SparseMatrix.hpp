#ifndef SPARSE_MATRIX_HPP_
#define SPARSE_MATRIX_HPP_
#include <vector>

class SparseMatrix { // abstract class
public:
    
    // Defining the pure virtual methods that _COO and _CSR have in common
    virtual int get_rows() = 0;
    virtual int get_columns() = 0;
    virtual int get_nonzeros() = 0;
    virtual void printmatrix() = 0;


    // Constructor
    SparseMatrix(const int input_size_rows, const int input_size_columns);

    // Copy constructor
    SparseMatrix(const SparseMatrix &other);

    // Implement access and write matrix entries by overloading the operator ()
    double &operator()(int &input_size_rows, int &input_size_columns);

    // Implement the matrix-vector product by overloading the operator *
    // SparseMatrix operator*(vettore);
    // Destructor
   virtual ~SparseMatrix() {
        delete[] matrix;
   }
private:
double *matrix; //magari ci serve il puntatore?
static unsigned int size_rows;
static unsigned int size_columns;
static unsigned int lunghezza;
int nnz; //number of non zeroes!
// the length of the following arrays is nnz (number of non-zeros)
// the array values contains all the nonzero values
std::vector<double> values;
// the array columns of int contains their corresponding columns indices
std::vector<int> cols;
};
#endif
