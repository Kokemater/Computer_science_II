#include "funcs.h"

int main(void)
{
	cout << "asdf" <<endl;
	ofstream outfile("results.txt");

    if (!outfile) {
        cout << "Error al abrir el archivo roots.txt" << endl;
        return -1;
    }
	const int N = 10;
	double eps = 1e-5;
	matrix <double> A(N,N), b(N,1), x(N,1), z(N,1), L(N,N), U(N,N);
	int Gauss_iterations, Jacobi_iterations;

	insert_rands_in_matrix(A, -100, 100,true);
	insert_rands_in_matrix(b, -100, 100,true);

	outfile << "Matrix A: "<<endl << A << endl << "b:" << b <<endl <<endl;


	Jacobi_iterations = Gauss_Seidel(A, b, x, eps);
	outfile <<"Solución usando Jacobi " << x << endl  << "(N_iterations) = " << Jacobi_iterations  << endl;
	outfile << "Error:" <<endl;
	outfile << error(A, b, x) << endl<<endl <<endl;

	Gauss_iterations = Gauss_Seidel(A, b, x, eps);
	outfile << "Solución usando Gauss-Seidel " <<endl << x << "(N_iterations) = " << Gauss_iterations <<endl ;
	outfile << "Error:" <<endl;
	outfile << error(A, b, x) << endl<<endl <<endl;

	LU(A,L,U);
	solve_LU(L,U,b,x);
	outfile << "Solución usando método LU " <<endl << x <<endl;
	outfile << "Error:" <<endl;
	outfile << error(A, b, x) << endl<<endl <<endl;

	matrix <double> x_correct = !A * b;
	outfile << "Solución analítica: (x = !A *b ) " <<endl << x_correct <<endl;

	cout << "Results copied in results.txt" << endl;


}