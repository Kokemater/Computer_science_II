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
int Jacobi_eigen_for_Off_plot(matrix <double> &A, matrix <double> &U, double &iter, double eps, double (*Off) (matrix <double>), ofstream &outfile); 
double Off(matrix <double> A);



#endif