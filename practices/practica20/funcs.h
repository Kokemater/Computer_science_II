#ifndef FUNCS_H
#define FUNCS_H

#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

#include "../../functions/matrix.h"
using namespace math;
void LU_tri(matrix <double> d, matrix <double> ds, matrix <double> df, matrix <double> b, int size, matrix <double> &delta_f, matrix <double> &delta, matrix <double> &delta_s, matrix <double> &z, matrix <double> &x);
void runge_kutta_4(double& x, matrix<double>& cond_iniciales, double h);


// Declaración de funciones
int calculate_rows(const string& file_name);
int calculate_cols(const string& file_name);
matrix<double> read_matrix_from_file(const string& file_name);




#endif