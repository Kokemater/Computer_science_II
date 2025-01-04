#!/bin/bash
g++ *.cpp -o derivatives
./derivatives
gnuplot graph.gp
gnuplot graph2.gp