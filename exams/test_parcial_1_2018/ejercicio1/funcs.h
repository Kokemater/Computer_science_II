#ifndef FUNCS_H
#define FUNCS_H

#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>

using namespace std;

#include "../../../functions/matrix.h"
using namespace math;

// Find roots funcs
double newton(double (*f)(double), double (*f_prime)(double), double x1, double eps, double &n_iterations_newton);
double secante(double (*f) (double), double x1, double x2, double eps, double &n_iterations_sec);
double biseccion(double (*f)(double), double a, double b, double eps, double &n_iterations);


#endif