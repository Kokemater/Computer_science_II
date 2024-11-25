#ifndef FUNCS_H
#define FUNCS_H

#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

#include "../../functions/matrix.h"
using namespace math;

int Gauss_Seidel(matrix<double> A, matrix<double> b, matrix<double> &x, double eps);
int Jacobi(matrix <double> A, matrix <double> b, matrix <double> &x, double eps);
void insert_rands_in_matrix(matrix <double> &A, double min, double max, bool dominancia_diagonal = false);
double error(matrix <double> A, matrix <double>b, matrix <double>x);
void LU(matrix <double> A, matrix <double> &L, matrix <double> &U);
void solve_LU(matrix<double> L, matrix<double> U, matrix<double> b, matrix<double>& x);
#endif