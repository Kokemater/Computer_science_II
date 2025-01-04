#include "funcs.h"

int main(void)
{
	matrix <double> A {
		{9, 3 ,-2, 2, 0.5},
		{1.6, 11, 4, -1.2, 2},
		{2, 3, 12, 2.3, -3},
		{-1, 3, -2, 16, 6},
		{2, 2, 3, -4, 15}
	};
	matrix <double> b{
		{1.7}, {3.3}, {2.3}, {6.6},{5.1}
	};
	int n = A.RowNo();
	double eps = 1e-2;
	matrix <double> exact_sol(n,1), x_jac(n,1), x_gauss(n,1);
	exact_sol = !A*b;
	ofstream n_iterations("n_iterations.txt");
	n_iterations << "eps   jacobi_iterations    gauss_iterations" << endl ;
	for (double eps = 1e-10; eps <=1e-2; eps*=10)
	{
	//cout << "Analitic Solution: " << endl << exact_sol << endl;
	int jacobi_iter = Jacobi(A, b, x_jac, eps);
	//cout << "Jacobi Solution " << endl << x_jac << endl;
	int gauss_iter = Gauss_Seidel(A, b, x_gauss, eps);
	//cout << "Gauss Solution " << endl << x_jac << endl;
	n_iterations << eps <<"          "<< jacobi_iter << "           " << gauss_iter << endl;
	}
}