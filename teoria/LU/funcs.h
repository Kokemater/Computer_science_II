#ifndef FUNCS_H
#define FUNCS_H

#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

#include "../../functions/matrix.h"
using namespace math;
double error(matrix <double> A, matrix <double>b, matrix <double>x);
void insert_rands_in_matrix(matrix <double> &A, double min, double max);
void LU(matrix <double> A, matrix <double> &L, matrix <double> &U);

#endif