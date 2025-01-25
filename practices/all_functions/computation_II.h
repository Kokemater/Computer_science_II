#ifndef MATHS_STUFF
#define MATH_STUFF

#include "math_stuff.h"

void runge_kutta_4(double& x, matrix<double>& cond_iniciales, double h, matrix <double(*)(matrix <double>, double)> Z_derivatives);
double gauss_6(double (*f)(double),double a, double b);


#endif