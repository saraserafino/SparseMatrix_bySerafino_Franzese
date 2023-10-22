#ifndef SPARSE_MATRIX_HPP_
#define SPARSE_MATRIX_HPP_
#include <vector>

class SparseMatrix { // abstract class
public:
    // If some common methods of COO and CSR don't act the same, they're defined as virtual
    virtual unsigned int get_num_rows() const = 0;
    // else they're not and we define them only in SparseMatrix
    unsigned int get_num_columns() const { return cols.size(); };
    unsigned int get_num_nnz() const { return values.size(); };

    // Redefining the operator () in both const and not-const version
    // in order to implement respectively access and write matrix entries
    virtual double operator()(unsigned int &input_size_rows, unsigned int &input_size_columns) const = 0;
    virtual double &operator()(unsigned int &input_size_rows, unsigned int &input_size_columns) = 0;

    void printmatrix();

    // Constructor
    SparseMatrix(const unsigned int &input_size_rows, const unsigned int &input_size_columns);

    // Copy constructor
    SparseMatrix(const SparseMatrix &other);

    // Implement the matrix-vector product by overloading the operator *
    // SparseMatrix operator*(vettore);

    // Virtual destructor
    virtual ~SparseMatrix() { delete[] matrix; };

private:
double *matrix; //forse ci serve il puntatore?
static unsigned int &size_rows;
static unsigned int &size_columns;
static unsigned int lunghezza;
unsigned int nnz; // number of non zeroes
// the length of the following two arrays is nnz
// the array values contains all the nonzero values
std::vector<double> values;
// the array cols contains their corresponding columns indices
std::vector<unsigned int> cols;
};
#endif
