#ifndef FUNCS_H
#define FUNCS_H

#include <iostream>

double derivada(double (*func)(double), double x, double h);
double my_integral(double (*func)(double), double a, double b, double h);

#endif