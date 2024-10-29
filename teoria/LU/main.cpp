#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

#include "../../functions/matrix.h"
using namespace math;

int main(void)
{
	int N;
	cout << "Matrix dimensions: ";
	cin >> N;
	cout << endl;

	matrix <double> A(N,N), L(N,N), U(N,N), b(N,1), z(N,1), x(N,1);
	insert_rands_in_matrix(A, -100, 100);
	insert_rands_in_matrix(b, -100, 100);

    ofstream outfile("matrix_results.txt");

    if (!outfile) {
        cout << "Error al abrir el archivo roots.txt" << endl;
        return -1;
    }
	outfile << "A =" << endl<< A  << "b = " <<endl << b <<endl;
	
	LU(A,L,U);
	outfile << "L =" << endl<< L  << "U = " <<endl << U <<endl;

	z = !L*b;
	x = !U*z;
	outfile << "z = " << endl << z << endl << "x = " << x << endl;
	double err = error(A, b, x);
	cout << "Error: " << err << endl;
	outfile << "Error= "<<  err << endl;

}