#!/bin/bash
set -x
mkdir -p build
g++ -Iinclude/ src/SparseMatrix.cpp -c -o build/SparseMatrix.o
g++ -Iinclude/ src/SparseMatrixCOO.cpp -c -o build/SparseMatrixCOO.o
g++ -Iinclude/ src/SparseMatrixCSR.cpp -c -o build/SparseMatrixCSR.o
g++ -Iinclude/ src/converter.cpp -c -o build/converter.o
g++ -Iinclude/ src/main.cpp -c -o build/main.o
g++ -std=c++17 -Wall -Wpedantic build/SparseMatrix.o build/SparseMatrixCOO.o build/SparseMatrixCSR.o build/converter.o build/main.o -o Homework01
set +x
if [ $? -eq 0 ]; then
    echo "Build successful! You can run the program using ./Homework01"
else
    echo "Build failed."
fi
