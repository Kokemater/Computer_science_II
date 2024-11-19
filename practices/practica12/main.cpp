#include "funcs.h"
#include <cmath>

int main(void)
{
	matrix <double> A = {
		{4,	-30, 60, -35, 112, -120},
		{-30, 44, 65, -234, 113, 211},
		{60, 65, 214, 345, 212, 114},
		{-35, -234, 345, 435, 23, 0},
		{112, 113, 212, 23, -312, 331},
		{-120, 211, 114, 0, 331,-234},
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

    ofstream outfile("points.txt");
	A = A_copy;
	Jacobi_eigen_for_Off_plot(A, U, iter,eps, Off, outfile);
	

}