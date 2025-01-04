#include "funcs.h"

int main(void)
{
	matrix <double> A {
		{1.05, -1.0, 0.0},
		{0.1667, 0.6667, 0.3333},
		{0.3333, 0.1667, 0.6667},
	};
	matrix <double> b {
		{0},
		{1260},
		{756},

	};
	matrix <double> x {
		{1000},
		{1000},
		{1000}
	};
	x = !A * b;
	cout << "x = " << endl << x <<endl;
	double eps = 0.01;
	int iter = Gauss_Seidel_modified(A, b, x, eps);
	//cout << fixed << setprecision(2);
	cout << x << endl << iter << endl;
}