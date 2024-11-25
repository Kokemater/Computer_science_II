#include "funcs.h"
#include <limits>

int main(void)
{

	//////////////// Ejercicio (1) /////////////////////

	const int N = 5;
	double eps = 1e-5;
	matrix <double> A(N,N), b(N,1), x(N,1), z(N,1), L(N,N), U(N,N);
	for(int i = 0; i < A.RowNo() ; i++)
	{
		for (int j = 0; j < A.ColNo(); j++)
		{
			if (i == j)
				A(i,j) = 5;
			else
				A(i,j) = 1;
		}
	}
	b = {{1,2,3,4,5}};
	b = ~b;

	// Apartado (a)
	LU(A,L,U);
	solve_LU(L, U, b, x);

	matrix <double> x_real = !A * b;
	cout << x << endl <<x_real<< endl;

	// Apartado (b)
	ofstream jacobi_file("jacobi.txt");
	int Jacobi_iterations = 0;
	cout << "Matrix A: "<<endl << A << endl << "b:" << b <<endl <<endl;

	matrix <double> x_jacobi(N, 1);
	for (double epsilon = 1e-3; epsilon >= 1e-12; epsilon*=0.1)
	{
		Jacobi_iterations = Jacobi(A, b, x_jacobi, epsilon);
		cout << "x_jacobi :" << endl << x_jacobi;
		jacobi_file << epsilon << " " << Jacobi_iterations << endl;
	}
	// Apartado (c)
	ofstream gauss_file("gauss.txt");
	int Gauss_iterations =0;
	matrix <double> x_gauss(N,1);
	for (double epsilon = 1e-3; epsilon >= 1e-12; epsilon*=0.1)
	{
		Gauss_iterations = Gauss_Seidel(A, b, x_gauss, epsilon);
		gauss_file << epsilon << " " << Gauss_iterations << endl;
	}
	// Apartado (d) : graph.gp

	// Apartado (e)
	double epsilon = std::numeric_limits<double>::epsilon();
	cout << epsilon << endl;
	Jacobi_iterations = Jacobi(A, b, x_jacobi, epsilon);
	Gauss_iterations = Gauss_Seidel(A, b, x_gauss, epsilon);
	cout << "Jacobi_iters: " << Jacobi_iterations << endl;
	cout << "Gauss_iters: " << Gauss_iterations << endl;
	return (0);
}