#ifndef FUNCS_H
#define FUNCS_H

#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
using namespace std;

#include "../../functions/matrix.h"
using namespace math;
void newton_raphson_non_linear(matrix <double(*)(double, double)> funciones, matrix < double(*)(double, double)> jacobiano, matrix <double> x1, double eps, double &n_iterations_newton, matrix <double> &solution);
void Broyden_non_linear(matrix <double (*)(double, double)> funciones, matrix <double> x1, matrix <double> x2, matrix <double> A_0, double eps, double &n_iterations_sec, matrix <double> &solution);
#endif