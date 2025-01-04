#!/bin/bash
g++ *.cpp -o derivatives
./derivatives
gnuplot new.gp
gnuplot new2.gp