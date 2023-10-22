#include "SparseMatrixCOO.hpp"
#include <vector>
#include <iostream>
class SparseMatrixCOO : public SparseMatrix {
public:
    SparseMatrixCOO(const int &input_size_rows, const int &input_size_columns)
    : SparseMatrix(const int input_size_rows, const int input_size_columns) {
        rows.size() = input_size_rows;
        cols.size() = input_size_columns;
        values.size() = nnz;
    }
    /*

   SparseMatrixCOO(const int &input_size_rows, const int &input_size_columns, int nnz)
    : size_rows(input_size_rows), size_columns(input_size_columns), nnz(nnz)
    {
        values.resize(nnz);
        rows.resize(nnz);
        cols.resize(nnz);
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
        rows[current_nnz] = index_row;
        cols[current_nnz] = index_col;
        current_nnz++;
    }

    void printmatrix_COO() {
        std::cout << "values = [";
        for (int i = 0; i < nnz - 1; ++i) {
            std::cout << values[i] << ", ";
        }
        std::cout << values[nnz - 1] << "]" << std::endl;
        std::cout << "rows = [";
        for (int i = 0; i < nnz - 1; ++i) {
            std::cout << rows[i] << ", ";
        }
        std::cout << rows[nnz - 1] << "]" << std::endl;
        std::cout << "columns = [";
        for (int i = 0; i < nnz - 1; ++i) {
            std::cout << cols[i] << ", ";
        }
        std::cout << cols[nnz - 1] << "]" << std::endl;
    }
*/
    unsigned int get_num_rows() const override {

    }

    double& operator()(unsigned int &input_size_rows, unsigned int &input_size_columns) override {
        if (input_size_rows < 0 || input_size_rows >= size_rows || input_size_columns < 0 || input_size_columns >= size_columns)
        {
            throw std::out_of_range("Index out of bounds");
        }
        for (int i = 0; i < values.size(); ++i) {
            if (rows[i] == )
        }
        return matrix[input_size_columns * input_size_rows + input_size_rows];
    }

    double operator()(unsigned int &input_size_rows, unsigned int &input_size_columns) const override {
        
    }

private:
// the length of the following array is nnz (number of non-zeros)
// the array rows contains the row indices
std::vector<unsigned int> rows;
};