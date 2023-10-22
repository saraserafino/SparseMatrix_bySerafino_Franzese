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
/*
    // Redefining the operator () in both const and not-const version
    // in order to implement respectively access and write matrix entries
    virtual double operator()(unsigned int &input_size_rows, unsigned int &input_size_columns) const = 0;
    virtual double &operator()(unsigned int &input_size_rows, unsigned int &input_size_columns) = 0;
*/
    // Define this class for the operator overload in both const and non-const version
    // i cout li aveva scritti il prof ma alla fine potremo toglierli, intanto teniamoli come check
    class SparseMatrixProxy {
        public:
        SparseMatrixProxy(double &val) : val(val) {}

        // Reading operator
        operator double() const {
            std::cout << "Reading operator (const)" << std::endl;
            return val;
        }
        // Writing operator
        SparseMatrixProxy &operator=(const double &x) {
            std::cout << "Writing operator (non-const)" << std::endl;
            val = x;
            return *this;
        }
        // Copy assignment operator
        SparseMatrixProxy &operator=(const SparseMatrixProxy &other) {
            std::cout << "Copy assignment (non-const)" << std::endl;
            val = other.val;
            return *this;
        }

        private:
        double &val;
    };

    // Constructor
    SparseMatrix(const unsigned int &input_size_rows, const unsigned int &input_size_columns);

    // Copy constructor
    SparseMatrix(const SparseMatrix &other);

    // Access operator for both reading and writing
    SparseMatrixProxy operator()(const unsigned int idx_row, const unsigned int idx_col) {
        return SparseMatrixProxy(matrix[idx_row][idx_col]);
        // alla fine quindi come la scrivevamo la matrice?
        // che qui il prof nel costruttore di Array metteva const std::vector<double> &data: data(data)
        //  quindi nel return metteva ArrayProxy(data[idx]);
        // più che altro non è matrice(lunghezza) perché vogliamo proprio dirgli di darci i due valori di riga e colonna
        // che oltretutto cambiano da COO a CSR quindi tocca far tutto questo virtuale
    }

    // Implement the matrix-vector product by overloading the operator *
    // SparseMatrix operator*(vettore);

    // Virtual destructor
    virtual ~SparseMatrix() { delete[] matrix; };
    void printmatrix();

private:
double *matrix; //forse ci serve il puntatore?
static unsigned int &size_rows;
static unsigned int &size_columns;
static unsigned int lunghezza;
unsigned int nnz; // number of non zeroes
// the length of the following two arrays is nnz
// the array values contains all the nonzero values
std::vector<double> values;
// the array columns contains their corresponding columns indices
std::vector<unsigned int> columns;
};
#endif
