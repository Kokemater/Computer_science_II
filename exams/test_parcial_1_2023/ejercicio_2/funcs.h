#ifndef FUNCS_H
#define FUNCS_H

#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>

using namespace std;

#include "../../../functions/matrix.h"
using namespace math;

int Gauss_Seidel_modified(matrix<double> A, matrix<double> b, matrix<double> &x, double eps);
int Jacobi(matrix <double> A, matrix <double> b, matrix <double> &x, double eps);
double error(matrix <double> A, matrix <double>b, matrix <double>x);
void LU(matrix <double> A, matrix <double> &L, matrix <double> &U);
void solve_LU(matrix<double> L, matrix<double> U, matrix<double> b, matrix<double>& x);
#endif