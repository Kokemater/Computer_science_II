#include "funcs.h"



void LU_tri(matrix <double> d, matrix <double> ds, matrix <double> df, matrix <double> b, int size, matrix <double> &delta_f, matrix <double> &delta, matrix <double> &delta_s, matrix <double> &z, matrix <double> &x)
{
	delta_s = ds;
	delta(0,0) = d(0,0);
	for (int i = 1; i < size; i++)
	{
		delta_f(0,i-1) = df(0,i-1) / delta(0,i-1);
		delta(0,i) = d(0,i) - delta_f(0,i-1) * ds(0,i-1);
	}
	z(0,0) = b(0,0);
	for (int i = 1; i < size; i++)
	{
		z(0,i) = b(0,i) - delta_f(0,i-1)*z(0,i-1);
	}
	x(0, size-1) = z(0,size-1)/delta(0,size-1);
	for (int i = size-2; i >= 0; i--)
	{
		x(0,i) = (z(0,i) - ds(0,i)*x(0,i+1))/delta(0,i);
	}
}
