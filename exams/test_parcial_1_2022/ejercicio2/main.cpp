#include "funcs.h"

int main(void)
{
	matrix <double> A(10,10);
	matrix <double> b(10,1);
	matrix <double> L(10,10), U(10,10);
	matrix <double> x(10,1), z(10,1);
	// Apartado (a)
	for(int i = 0; i < 10; i++)
	{
		b(i,0) = i;
	}
	insert_rands_in_matrix(A, 0, 10, true);
	// show matrix
	ofstream see_matrix("see_matrix.txt");
	for (int i = 0; i < A.RowNo(); i++)
	{
		for (int j = 0; j < A.ColNo(); j++)
		{
			see_matrix << A(i,j);
			see_matrix << " ";
		}
		see_matrix << endl;
	}
	if (A.IsSingular())
		cout << "Error, el sistema no es SCD"<<endl;

	// Apartado (b)
	LU(A, L, U);
	solve_LU(L, U, b, x);

	
	int n = A.RowNo();
	double eps = 1e-2;
	matrix <double> exact_sol(n,1), x_jac(n,1), x_gauss(n,1);
	exact_sol = !A*b;
	cout << exact_sol << endl;
	cout << x << endl;


	// Apartados (c) y (d)
	ofstream n_iterations("n_iterations.txt");
	for (double eps = 1e-3; eps >=1e-12; eps*=0.1)
	{
	x_jac.Null();
	x_gauss.Null();
	int gauss_iter = Gauss_Seidel(A, b, x_gauss, eps);
	cout << "gauss_iter = " << gauss_iter <<endl;
	int jacobi_iter = Jacobi(A, b, x_jac, eps);
	cout << "jacobi_iter = " << gauss_iter <<endl;

	n_iterations << eps <<" "<< jacobi_iter << " " << gauss_iter << endl;
	}


}