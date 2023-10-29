#!/bin/bash
set -x
mkdir -p build
g++ -std=c++17 -Iinclude/ src/SparseMatrix.cpp -c -o build/SparseMatrix.o
g++ -std=c++17 -Iinclude/ src/SparseMatrixCOO.cpp -c -o build/SparseMatrixCOO.o
g++ -std=c++17 -Iinclude/ src/SparseMatrixCSR.cpp -c -o build/SparseMatrixCSR.o
g++ -std=c++17 -Iinclude/ src/main.cpp -c -o build/main.o
g++ -std=c++17 -Wall -Wpedantic build/SparseMatrix.o build/SparseMatrixCOO.o build/SparseMatrixCSR.o build/main.o -o build/HomeworkSF
set +x
if [ $? -eq 0 ]; then
    echo "Build successful! You can run the program using ./build/HomeworkSF"
else
    echo "Build failed."
fi