#include "funcs.h"

int main(void)
{
	matrix <double> A {
		{8, -5, 3, -1, 4},
		{-5, 4, 1, -1, -2},
		{3, 1, 7, 2, 1},
		{-1, -1, 2, 9, 4},
		{4, -2, 1, 4, 14}
	};
	matrix <double> A_copy = A;
	double n = A.RowNo();
	matrix <double> B (n,n);
	matrix <double> U (n,n);
	double eps = 1e-7;
	double iter;
	int errors;
	set_precission(eps);
	for (int i = 1 ; i <= 4 ; i++)
	{
		A.Unit();
		for(int j = 0; j < i; j++)
		{
			A = A * A_copy;
		}
		cout << "RESULTS: A^" << i<< endl;

		iter = 0;
		errors = Jacobi_eigen(A, U, iter, eps);
		matrix <double> eigenvec(A.RowNo(),1);
		matrix <double> eigenval(A.RowNo(),1);
		// Print results
		if (!errors)
		{
			cout << "La traza de A siempre es la misma y vale : " << A.Traza() << endl;
			cout << "Iterations : " << iter <<endl;
			cout << "U " << endl << U;
			eigenval = print_eigen_val(A);
		}
	}

	cout << "-------------------------------------------------" << endl;
	cout << "-------------------------------------------------" << endl;
	double of = Off(A_copy);
	cout << "of : " << of << endl;
    ofstream outfile("points.txt");
	A = A_copy;
	Jacobi_eigen_for_Off_plot(A, U, iter,eps, Off, outfile);
}