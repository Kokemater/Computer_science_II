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


void diferencias_finitas(int N, double h, matrix<double>& u) {
    int size = N - 1; // Tamaño del sistema
    matrix<double> d(1, size), ds(1, size - 1), df(1, size - 1), b(1, size);
    matrix<double> delta_f(1, size - 1), delta(1, size), delta_s(1, size - 1);
    matrix<double> z(1, size), x(1, size);

    for (int i = 0; i < size; ++i) {
        double xi = h * (i + 1);
        d(0, i) = 2.0 + h * h * (1 - xi * xi); // Término diagonal
        b(0, i) = h * h * std::exp(-xi * xi); // Término independiente
        if (i > 0) ds(0, i - 1) = -1.0;      // Subdiagonal
        if (i < size - 1) df(0, i) = -1.0;   // Superdiagonal
    }

    // Condiciones de frontera
    b(0, 0) += 40.0; // u(0) = 40
    b(0, size - 1) += 40.0; // u(1) = 40

    // Resolvemos el sistema usando LU_tridiagonal
    LU_tri(d, ds, df, b, size, delta_f, delta, delta_s, z, x);

    // Guardamos la solución
    for (int i = 0; i < size; ++i) {
        u(0, i + 1) = x(0, i);
    }
    u(0, 0) = 40.0;      // Frontera izquierda
    u(0, N) = 40.0;      // Frontera derecha
}

