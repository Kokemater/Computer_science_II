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
	matrix <double> B (A.RowNo(), A.ColNo());
	matrix <double> U (A.RowNo(), A.ColNo());
	double eps = 1e-7;
	set_precission(eps);
	double iter = 0;
	cout << A <<endl;
	int errors = Jacobi_eigen(A, U, iter, eps);
	matrix <double> eigenvec(A.RowNo(),1);
	matrix <double> eigenval(A.RowNo(),1);
	// Print results
	if (!errors)
	{
		cout << "RESULTS: " <<endl;
		cout << "Iterations : " << iter <<endl;
		cout << "U " << endl << U;
		eigenval = print_eigen_val(A);
	}
	// Check 
	cout << "Comprobation: " << endl;
	for (int i = 0; i < U.ColNo(); i++)
	{
		eigenvec = get_eigen_vect(U,i);
		cout << endl << A_copy * eigenvec - eigenval(i,0) * eigenvec << endl;
	}
}