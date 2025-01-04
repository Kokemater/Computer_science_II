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
long double newton(long double (*f)(long double), long double (*f_prime)(long double), long double x1, long double eps, long double &n_iterations_newton);
long double secante(long double (*f) (long double), long double x1, long double x2, long double eps, long double &n_iterations_sec);
long double biseccion(long double (*f)(long double), long double a, long double b, long double eps, long double &n_iterations);


#endif