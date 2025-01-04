#ifndef FUNCS_H
#define FUNCS_H

#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>

using namespace std;

#include "../../functions/matrix.h"
using namespace math;

double trapezoidal(double (*f)(double), double a, double b, double tau);
double simpson(double (*f) (double), double a, double b, double tau);
double gauss_6(double (*f)(double),double a, double b);



#endif