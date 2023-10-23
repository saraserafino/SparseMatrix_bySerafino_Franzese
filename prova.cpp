#include "SparseMatrixCOO.hpp"
#include <vector>
#include <iostream>

int main(){
  std::vector<double> values = {1,2,3};
  std::vector<unsigned int> columns = {0,2,4};
  std::vector<unsigned int> rows = {1,0,3};
  SparseMatrixCOO m(values, rows, columns);
  std::cout << "matrix m with " << m.get_num_rows() << "rows and " << m.get_num_columns() << " columns\n";
  std::cout << "m(1,0): " << m(1,0) << std::endl;
  m(2,2) = 100;
  std::cout << "Dopo m(2,2) = 100, cout di m(2,2) da: " << m(2,2) << std::endl;
  return 0;
}



#include <iostream>
#include "SparseMatrix.hpp"
#include "SparseMatrixCOO.hpp"
/*#include "SparseMatrixCSR.hpp"
#include "converter.hpp"

// Preferred to run some tests with boolean functions. In this way the main is cleaner and there are less lines per test
// which is faster to remove by commenting if you don't want to run them every time
bool check_matrix_vector_of_1_product(std::vector<double> matrix) {
    std::vector<int> vector1(size_rows, 1); // vector of 1 with lenght the number of rows of the matrix
    // Calculate the array where every entry is the sum of the i-th row of the matrix
    for (unsigned int i = 0; i < size_rows; ++i) {
        std::vector<double> sum_rows[i] = 0; // initializate the result to 0
        for (unsigned int j = 0; j < size_columns; ++j) {
            sum_rows[i] += A[i,j];
        }
    }
    // If correct, the matrix-vector product must give the sum of the i-th row
    if (matrix*vector1 != sum_rows) {
        return false; // It doesn't work well
    }
    return true; // It works
}

// sono stanca, nella seguente funzione mancano tante cose fra cui:
// il vettore probabilmente va inizializzato dentro un for perché cambia ogni volta che
// cambiamo riga cioè è 1 0 0, 0 1 0, 0 0 1 etc, quindi devi tenerne conto
// e ovviamente scrivere solo un return false-true e non i quindi devi trovare
// un modo per controllarli tutti ma stampare solo un risultato (con qualcosa tipo if (corretto1 && corretton &&) return true)??
bool check_matrix_canonical_basis_product(matrix) {
    std::vector<int> vector1(size_rows, 1); // canonical vector with lenght the number of rows of the matrix
    // Calculate the array where every entry is the sum of the i-th column of the matrix
    for (unsigned int j = 0; j < size_columns; ++j) {
        std::vector<double> sum_columns[j] = 0; // initializate the result to 0
        for (unsigned int i = 0; i < size_rows; ++i) {
            sum_columns[i] += A[i,j];
        }
    }
    // If correct, the matrix-vector product must give the i-th column of the matrix
    if (matrix*vector1 != sum_columns) {
        return false; // It doesn't work well
    }
    return true; // It works
    }
*/
int main () {
/*const double input1[][] = {[1,0,0],[0,2,0],[1,0,0]};
SparseMatrixCOO matriceCOO(4, 5, 6); // matrice 4x5 con 6 elementi nnz
matriceCOO.setElement(0, 2, 3.1);
matriceCOO.setElement(0, 4, 4);
matriceCOO.setElement(1, 2, 5);
matriceCOO.setElement(1, 4, 7.4);
matriceCOO.setElement(3, 1, 2);
matriceCOO.setElement(3, 3, 6);
matriceCOO.printmatrix();
// Proviamo con la stessa matrice di prima ma con altro metodo
SparseMatrixCSR matriceCSR(4, 5, 6);
matriceCSR.setElement(0, 2, 3.1);
matriceCSR.setElement(0, 4, 4);
matriceCSR.setElement(1, 2, 5);
matriceCSR.setElement(1, 4, 7.4);
matriceCSR.setElement(3, 1, 2);
matriceCSR.setElement(3, 3, 6);
matriceCSR.printmatrix();*/

//con la cosa del Proxy del prof dovremmo poter scrivere:
SparseMatrixCOO A{{valori}}; //solo che lui faceva Array perché non era abstract class, noi non possiamo fare SparseMatrix
const double x = A(2, 3); // const version
A(2, 3) = 5.7; // non-const version
// Let's run some tests to validate the correctness of the program
    
/*std::cout << "Does the matrix-vector product work well?" << std::endl << "Multiplying the matrix for a vector of 1 it's "
<< check_matrix_vector_of_1_product(matrix) << std::endl << "Multiplying the matrix for the i-th vector of the canonical basis it's "
<< check_matrix_canonical_basis_product(matrix) << std::endl; */
return 0;
}