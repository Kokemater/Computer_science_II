#ifndef FUNCS_H
#define FUNCS_H

#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>

using namespace std;

#include "../../functions/matrix.h"
using namespace math;
void set_precission(double precission);
int Jacobi_eigen(matrix <double> &A, matrix <double> &U, double &iter, double eps);
matrix <double> print_eigen_val(matrix <double> A);
matrix <double> get_eigen_vect(matrix <double> A, int pos);
#endif