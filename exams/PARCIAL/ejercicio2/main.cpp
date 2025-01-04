#include "funcs.h"

void create_matrix(matrix <long double> &A)
{
	for(int i = 0; i <A.RowNo(); i++)
	{
		for (int j = 0; j < A.ColNo(); j++)
		{
			A(i,j) = sin(M_PI*0.1*(i + j)) + cos(M_PI*0.1*(i-j));
		}
	}
}
int main(void)
{
	matrix <long double> A(10,10);
	create_matrix(A);
	if (!A.IsSymmetric())
	{
		cout << "Error: A is not symmetric" << endl;
		return (1);
	}
	if (A.IsSingular())
	{
		cout << "Error: A is singular" << endl;
		return (1);
	}
	cout << "Matrix A :" << endl;
	cout << A << endl;
	matrix <long double> A_copy = A;

	long double n = A.RowNo();
	matrix <long double> B (n,n);
	matrix <long double> U (n,n);
	long double eps = 1e-7;
	long double iter;
	int errors;

	// Apartado (a) y (b)
	// Precisión 1e-3
	eps = 1e-3;
	iter = 0;
	errors = Jacobi_eigen(A, U, iter, eps);
	if (errors)
	{
		cout << "Error" << endl;
		return (1);
	}
	cout << A << endl;
	cout << " Se han realizado " << iter << " interaciones para precisión = 1e-3" << endl;
	// Precisión 1e-12
	eps = 1e-12;
	U.Null();
	A = A_copy;
	iter = 0;
	errors = Jacobi_eigen(A, U, iter, eps);
	if (errors)
	{
		cout << "Error" << endl;
		return (1);
	}
	cout << " Se han realizado " << iter << " interaciones para precisión = 1e-12" << endl;


	matrix <long double> eigenvec(A.RowNo(),1);
	matrix <long double> eigenval(A.RowNo(),1);
	matrix <long double> diff(A.RowNo(),1);

	// Apartado (c)
	// Primero trabajaremos con el resultado de 1e-12

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
		diff = A_copy * eigenvec - eigenval(i,0) * eigenvec;
		cout << endl << "|| A- lambda_i*I ||v_i =  " << diff.Norm(2) << endl;
	}

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
		diff = A_copy * eigenvec - eigenval(i,0) * eigenvec;
		cout << endl << "|| A- lambda_i*I || v_i:" << diff.Norm(2) << endl;
	}

	// Apartado (d) realizado en informe





	/* PRUEBA DE NÚMERO DE ITERACIONES EN OTRA PRECISIÓN POR EJEMPLO eps = 16
	A = A_copy;
	eps = 1e-16;
	iter = 0;
	errors = Jacobi_eigen(A, U, iter, eps);
	if (errors)
	{
		cout << "Error" << endl;
		return (1);
	}
	cout << A << endl;
	cout << " Se han realizado " << iter << " interaciones para precisión = 1e-16" << endl;
	*/

}