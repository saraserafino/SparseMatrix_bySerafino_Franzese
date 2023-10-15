#include "SparseMatrixCOO.hpp"
#include <vector>

class SpareMatrixCOO : public SparseMatrix {
public:
// per ognuno dei punti richiesti (get number of rows, columns, read an entry etc) dobbiamo fare una funzione come
    /*
    int get_rows() override {

    }
    */
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
        rows[current_nnz] = index_row;
        cols[current_nnz] = index_col;
        values[current_nnz] = value;
        current_nnz++;
    }

    void printCOO() {
        for (int i = 0; i < nnz; ++i) {
            std::cout << "values[" << i << "] = " << values[i] << ", rows[" << i << "] = " << rows[i]
                      << ", cols[" << i << "] = " << cols[i] << std::endl;
        }
    }


private:
// the length of the following array is nnz (number of non-zeros)
// the array rows of int contains their corresponding rows indices
std::vector<int> rows;
int current_nnz;
};

/*
nel main scriverai per esempio
SparseMatrixCOO matrice1(4, 5, 6); // matrice 4x5 con 6 elementi nnz
matrice1.setElement(0, 2, 3.1);
matrice1.setElement(0, 4, 4);
matrice1.setElement(1, 2, 5);
matrice1.setElement(1, 4, 7.4);
matrice1.setElement(3, 1, 2);
matrice1.setElement(3, 3, 6);
matrice1.printCOO();

*/