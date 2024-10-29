#include "funcs.h"

static void initialize_vectors(matrix <double> &d, matrix <double> &ds, matrix <double> &df)
{
	d = {{15, 7 , 9 ,11}};
	df = {{1.9, -1.3, -2.5}};
	ds = {{3.2, 1.1, 1.3}};
}
int main(void)
{
	// Given data
	int size = 4;
	matrix <double> d(1,size), ds(1, size-1), df(1, size-1);
	initialize_vectors(d, ds, df);
	matrix <double> b = {{1.9, 3.1, 2.2, 5.3}};

	// Data obtained after LU_tri
	matrix <double> delta_f(1,size-1), delta(1,size), delta_s(1,size -1), z(1,size), x(1,size);
	LU_tri(d, ds, df, b, size, delta_f, delta, delta_s, z, x);

	// Print results
	cout << "d = " << d << endl;
	cout << "ds = " << ds << endl;
	cout << "df = " << df << endl;
	cout << "b = " << b << endl;
	cout << "delta_f = " << delta_f << endl;
	cout << "delta = " << delta << endl;
	cout << "delta_s = " << delta_s << endl;
	cout << "z = " << z << endl;
	cout << "x = " << x << endl;

	// Comparación de la solución con la real usando Ax = b -> x = !A *b
	matrix <double> A {
		{15, 3.2, 0,0},
		{1.9, 7,1.1, 0},
		{0, -1.3, 9,1.3},
		{0,0,-2.5, 11}
	};
	b = ~b;
	x = !A*b;
	cout << ~x << endl;
	cout << "EN EFECTO LOS VALORES CONCUERDAN";

}
