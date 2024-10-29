#ifndef FUNCS_H
#define FUNCS_H

#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

#include "../../functions/matrix.h"
using namespace math;
void LU_tri(matrix <double> d, matrix <double> ds, matrix <double> df, matrix <double> b, int size, matrix <double> &delta_f, matrix <double> &delta, matrix <double> &delta_s, matrix <double> &z, matrix <double> &x);

#endif