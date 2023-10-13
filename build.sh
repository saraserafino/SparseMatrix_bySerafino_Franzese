#!/bin/bash
set -x
mkdir -p build
g++ -Iinclude/ src/calculator.cpp -c -o build/calculator.o
g++ -Iinclude/ src/main.cpp -c -o build/main.o
g++ -std=c++17 -Wall -Wpedantic build/calculator.o build/main.o -o Homework01
set +x
if [ $? -eq 0 ]; then
    echo "Build successful! You can run the program using ./Homework01"
else
    echo "Build failed."
fi
