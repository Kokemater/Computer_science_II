#!/bin/bash
g++ main.cpp all_functions/*.cpp -o diferencias_finitas
./diferencias_finitas
g++ compare.cpp 
./a.out
gnuplot c.gp
code c.png
