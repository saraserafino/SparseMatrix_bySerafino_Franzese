#include "SparseMatrixCSR.hpp"
#include <vector>

class SpareMatrixCSR : public SparseMatrix {
public:
// per ognuno dei punti richiesti (get number of rows, columns, read an entry etc) dobbiamo fare una funzione come
    /* int get_rows() override {

    }
    */
   SparseMatrixCSR(const int &input_size_rows, const int &input_size_columns, int nnz)
    : size_rows(input_size_rows), size_columns(input_size_columns), nnz(nnz)
    {
        values.resize(nnz);
        cols.resize(nnz);
        row_idx.resize(size_rows + 1, 0); // initialize row_idx with 0
        current_nnz = 0;
    }

    void setElement(int index_row, int index_col, double value) {
        if (index_row < 0 || index_row >= size_rows || index_col < 0 || index_col >= size_columns)
        {
            throw std::out_of_range("Index out of bounds.");
        }
        if (current_nnz >= nnz) {
            throw std::overflow_error("Too many non-zeros.");
        }
        values[current_nnz] = value;
        cols[current_nnz] = index_col;
        current_nnz++; 
        row_idx[index_row + 1]++;
    }

    void printmatrix() override {
        std::cout << "values = [";
        for (int i = 0; i < nnz - 1; ++i) {
            std::cout << values[i] << ", ";
        }
        std::cout << values[nnz - 1] << "]" << std::endl;
        std::cout << "columns = [";
        for (int i = 0; i < nnz - 1; ++i) {
            std::cout << cols[i] << ", ";
        }
        std::cout << cols[nnz - 1] << "]" << std::endl;
        // Calculate the cumulative sum in row_idx
        for (int i = 1; i <= index_row; ++i) {
            row_idx[i] += row.idx[i - 1];
        }
        std::cout << "row_idx = [";
        for (int i = 0; i <= index_row - 1; ++i) {
            std::cout << row_idx[i] << ", ";
        }
        std::cout << row_idx[index_row] << "]" << std::endl;
    }
private:
// the array rows_idx of int contains the cumulative number of nonzero entries up to the
// i-th row excluded. Its length is m+1 with m number of rows of A
std::vector<int> rows_idx;
};
