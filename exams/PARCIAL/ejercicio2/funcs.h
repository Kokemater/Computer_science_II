#ifndef FUNCS_H
#define FUNCS_H

#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>

using namespace std;

#include "../../../functions/matrix.h"
using namespace math;
void set_precission(long double precission);
int Jacobi_eigen(matrix <long double> &A, matrix <long double> &U, long double &iter, long double eps);
matrix <long double> print_eigen_val(matrix <long double> A);
matrix <long double> get_eigen_vect(matrix <long double> A, int pos);
int Jacobi_eigen_for_Off_plot(matrix <long double> &A, matrix <long double> &U, long double &iter, long double eps, long double (*Off) (matrix <long double>), ofstream &outfile); 
long double Off(matrix <long double> A);


#endif